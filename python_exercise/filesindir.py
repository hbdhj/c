import sys
import os, os.path

def getAllFilesUnderDir(dirName, fileSuffix=""):
    fileList = []
    if os.path.exists(dirName):
        for entry in os.scandir(dirName):
            if entry.name.startswith('.'):
                print("skip hiden directory or file: "+entry.name)
            elif entry.is_file():
                if len(fileSuffix)>0 and entry.name[-1-len(fileSuffix):]!='.'+fileSuffix:
                    pass
                else:
                    fileName = dirName + '/' + entry.name
                    fileList.append(fileName)
    return fileList

#if __name__ == "__main__":
#    file_list = getAllFilesUnderDir(sys.argv[1], sys.argv[2])
#    print("we have "+ str(len(file_list)) + " files under " + sys.argv[1] )
#    for file in file_list:
#        print(file)