import sys
import os, os.path
import operator

# class FileLineCounter

# class CFileLineCounter

class DirectoryLoop:

    languageMap={"h":"c", "c":"c", "py":"python", "swift":"swift", "json":"ajax", "php":"php", "js":"javascript",
                 "m":"objective-c", "html":"html", "java":"java", "rb":"ruby", "cpp":"c"}
    skipList=["sqlite3", "pyc", "png", "gif", "jpg", "ico"]

    def __init__(self, dirName):
        self.dir = dirName
        self.unkown_file_type=[]
        self.languageFileCounter={}
        self.caredFiles={}

    def countFiles(self, path=""):
        print("Now we are going to count all files under directory "+self.dir)
        if path=="":
            path = self.dir

        if os.path.exists(path):
            for entry in os.scandir(path):
                if entry.name.startswith('.'):
                    print("skip hiden directory or file: "+entry.name)
                elif entry.is_file():
                    print(entry.name + " is a file")
                    sufix = os.path.splitext(entry.name.lower())[1][1:]
                    if sufix not in DirectoryLoop.languageMap.keys():
                        if sufix not in self.unkown_file_type:
                            self.unkown_file_type.append(sufix)

                    if sufix not in self.languageFileCounter.keys():
                        self.languageFileCounter[sufix]=1
                    else:
                        self.languageFileCounter[sufix]+=1

                    if sufix in DirectoryLoop.languageMap.keys():
                        if sufix not in self.caredFiles.keys():
                            self.caredFiles[sufix]=1
                        else:
                            self.caredFiles[sufix]+=1

                elif entry.is_dir():
                    print(entry.name + " is a directory")
                    self.countFiles(path+"/"+entry.name)
                else:
                    print("skip it!")
        return 0

    def printUnkownFileType(self):
        print(self.unkown_file_type)

    def printFileCounterSorted(self):
        #print(self.unkown_file_type)
        #for key, value in sorted(self.languageFileCounter.iteritems(), key=lambda (k,v): (v,k)):
        #    print "%s: %s" % (key, value)
        sorted_dict = sorted(self.languageFileCounter.items(), key=operator.itemgetter(1))
        print(sorted_dict)

if __name__ == "__main__":
    #print("main")
    # print(sys.version)
    #print(sys.argv[0])
    d = DirectoryLoop(sys.argv[1])
    d.countFiles()
    d.printUnkownFileType()
    d.printFileCounterSorted()
    print(d.caredFiles)
