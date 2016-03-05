import sys
import os, os.path
import operator
import hashlib
import os


class DuplicateFilesFinder:

    def __init__(self, dirName):
        self.dir = dirName
        self.sizeFileMap={}
        self.resultFiles={}
        self.suspectFiles={}

    def FindSuspectFiles(self, path=""):
        print("Now we are going to search all files under directory "+self.dir)
        if path=="":
            path = self.dir

        if os.path.exists(path):
            for entry in os.scandir(path):
                if entry.name.startswith('.'):
                    print("skip hiden directory or file: "+entry.name)
                elif entry.is_file():
                    #print(entry.name + " is a file")
                    fullFileName = path+"/"+entry.name
                    fileSize=os.path.getsize(fullFileName)
                    if fileSize in self.sizeFileMap.keys():
                        if fileSize not in self.suspectFiles.keys():
                            self.suspectFiles[fileSize]=[]
                            self.suspectFiles[fileSize].append(self.sizeFileMap[fileSize])
                            self.suspectFiles[fileSize].append(fullFileName)
                        else:
                            self.suspectFiles[fileSize].append(fullFileName)
                    else:
                        self.sizeFileMap[fileSize]=fullFileName
                elif entry.is_dir():
                    print(entry.name + " is a directory")
                    self.FindSuspectFiles(path+"/"+entry.name)
                else:
                    print("skip it!")
        return 0

    def printSuspectFiles(self):
        sortedSuspectFiles=sorted(self.suspectFiles.items(), key=operator.itemgetter(0))
        for size, list in sortedSuspectFiles:
            print("\nwe have "+str(len(list))+" files shared the same file size "+str(size))
            for file in list:
                print(file)

    def confirmWithMD5(self):
        suspectFiles=sorted(self.suspectFiles.items(), key=operator.itemgetter(0))
        #print(suspectFiles)
        for size, list in suspectFiles:
            #print(size)
            cksumFileMap={}
            for file in self.suspectFiles[size]:
                #print(file)
                cksum=hashlib.md5(open(file, 'rb').read()).hexdigest()
                if cksum in self.resultFiles.keys():
                    self.resultFiles[cksum].append(file)
                elif cksum in cksumFileMap.keys():
                    self.resultFiles[cksum]=[]
                    self.resultFiles[cksum].append(cksumFileMap[cksum])
                    del cksumFileMap[cksum]
                    self.resultFiles[cksum].append(file)
                else:
                    cksumFileMap[cksum]=file


    def printFinalResult(self):
        for checksum in self.resultFiles:
            print("\nwe have "+str(len(self.resultFiles[checksum]))+" files shared the same checksum "+checksum)
            for file in self.resultFiles[checksum]:
                print(file)
    #hashlib.md5(open(full_path, 'rb').read()).hexdigest()

if __name__ == "__main__":
    d = DuplicateFilesFinder(sys.argv[1])

    d.FindSuspectFiles()
    d.printSuspectFiles()

    #d.confirmWithMD5()
    #d.printFinalResult()
