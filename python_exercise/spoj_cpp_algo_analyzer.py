import sys
import os, os.path
from filesindir import getAllFilesUnderDir

def getAlgoFromSpojCode(dirName):
    algo_dict = {}
    files_list = []
    if os.path.exists(dirName):
        files_list = getAllFilesUnderDir(dirName, 'cpp')

    for fileName in files_list:
        with open(fileName, 'rt') as f:
            try:
                for line in f:
                    if line.find("ALGO")>=0:
                        #print(line)
                        fields = line.split(':')
                        if len(fields)==2:
                            algo = fields[1].strip().lower()
                            if algo in algo_dict.keys():
                                algo_dict[algo].append(fileName)
                            else:
                                algo_dict[algo]=[]
                                algo_dict[algo].append(fileName)

            except UnicodeDecodeError:
                print("error to decode file "+fileName)

    sorted_algo_dict= sorted(algo_dict.items(), key=lambda d:len(d[1]), reverse = True)
    for algo, filelist in sorted_algo_dict:
        print(algo+' : '+str(len(filelist))+" files")
        print(filelist)

if __name__ == "__main__":
    getAlgoFromSpojCode(sys.argv[1])