import sys
import os, os.path
import operator

class FileLineCounter:
    def __init__(self, fileName):
        self.fileName = fileName
        self.lineNumber = 0

    def process(self):
        print("process "+ self.fileName )
        fh = open(self.fileName, 'r')
        try:
            for line in fh.readlines():
                if len(line.strip())>0:
                    if self.validLine(line.strip()):
                        self.lineNumber+=1
        except UnicodeDecodeError:
            print("error to decode file "+self.fileName)
        finally:
            fh.close()

    def validLine(self, line):
        return True

    def getLineNumber(self):
        return self.lineNumber

class CFileLineCounter(FileLineCounter):
    def __init__(self, fileName):
        FileLineCounter.__init__(self, fileName)

    def getLineNumber(self):
        return FileLineCounter.getLineNumber(self)

    def validLine(self, line):
        if len(line)>=2:
            #print(line)
            if line[0]=='/' and line[1]=='/':
                return False
        return True

class PythonFileLineCounter(FileLineCounter):
    def __init__(self, fileName):
        FileLineCounter.__init__(self, fileName)

    def getLineNumber(self):
        return FileLineCounter.getLineNumber(self)

    def validLine(self, line):
        if len(line)>=1:
            #print(line)
            if line[0]=='#':
                return False
        return True

class DirectoryLoop:
    languageMap={"h":"c", "c":"c", "py":"python", "swift":"swift", "json":"ajax", "php":"php", "js":"javascript",
                 "m":"objective-c", "html":"html", "java":"java", "rb":"ruby", "cpp":"c", "css":"css", "go":"go"}
    skipList=["sqlite3", "pyc", "png", "gif", "jpg", "ico"]

    def __init__(self, dirName):
        self.dir = dirName
        self.unkown_file_type=[]
        self.languageFileCounter={}
        self.caredFileNumber={}
        self.caredFiles={}
        self.languageLines={}

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
                            self.caredFileNumber[sufix]=1
                            self.caredFiles[sufix]=[]
                        else:
                            self.caredFileNumber[sufix]+=1
                        self.caredFiles[sufix].append(path+"/"+entry.name)
                        filePath=path+"/"+entry.name
                        lang = self.languageMap[sufix]
                        print(filePath+" is "+lang)
                        fc=None
                        if lang=="c":
                            fc = CFileLineCounter(filePath)
                        elif lang=="python":
                            fc = PythonFileLineCounter(filePath)
                        else:
                            fc = FileLineCounter(filePath)
                        fc.process()
                        lineNumber=fc.getLineNumber()
                        if lang not in self.languageLines.keys():
                            self.languageLines[lang]=0
                        self.languageLines[lang]+=lineNumber

                elif entry.is_dir():
                    print(entry.name + " is a directory")
                    self.countFiles(path+"/"+entry.name)
                else:
                    print("skip it!")
        return 0

    def printUnkownFileType(self):
        print(self.unkown_file_type)

    def printFileCounterSorted(self, moreAhead=True):
        sorted_dict = sorted(self.languageFileCounter.items(), key=operator.itemgetter(1), reverse=moreAhead)
        print(sorted_dict)

    def printFileNumbers(self, moreAhead=True):
        sorted_dict = sorted(self.caredFileNumber.items(), key=operator.itemgetter(1), reverse=moreAhead)
        print(sorted_dict)

    def printLanguageLines(self, moreAhead=True):
        sorted_dict = sorted(self.languageLines.items(), key=operator.itemgetter(1), reverse=moreAhead)
        print(sorted_dict)

if __name__ == "__main__":
    d = DirectoryLoop(sys.argv[1])
    d.countFiles()
    d.printFileNumbers()
    d.printLanguageLines()
