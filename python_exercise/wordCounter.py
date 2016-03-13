import sys
import requests
from bs4 import BeautifulSoup
import operator
import os, os.path

def countWordsInUrl(url):
    word_list = []
    source_code = requests.get(url).text
    soup = BeautifulSoup(source_code)
    for post_text in soup.findAll('a', {'class' : 'index_singlelistingTitles'}):
        content = post_text.string
        words = content.lower().split()
        for each_word in words:
            print(each_word)
            word_list.append(each_word)


def countWordsInAllFilesUnderDir(dirName):
    word_list = []
    if os.path.exists(dirName):
            for entry in os.scandir(dirName):
                if entry.name.startswith('.'):
                    print("skip hiden directory or file: "+entry.name)
                elif entry.is_file() and entry.name[-4:]=='.txt':
                    print(entry.name)
                    fileName = dirName + '/' + entry.name
                    with open(fileName, 'rt') as f:
                        try:
                            for line in f:
                                words = line.lower().split()
                                for each_word in words:
                                    #print(each_word)
                                    word_list.append(each_word)
                        except UnicodeDecodeError:
                            print("error to decode file "+fileName)
    clean_up_list(word_list)
    create_dictionary(word_list)

def countWordsInTxt(fileName):
    word_list = []
    with open(fileName, 'rt') as f:
        for line in f:
            words = line.lower().split()
            for each_word in words:
                #print(entry.name)
                word_list.append(each_word)
    clean_up_list(word_list)
    create_dictionary(word_list)

def clean_up_list(word_list):
    clean_word_list = []
    for word in word_list:
        symbols = "!@#$%^&*()_+{}:\"<>?,./;'[]-='"
        for i in range(0, len(symbols)):
            word = word.replace(symbols[i], '')
        if len(word) > 0:
            clean_word_list.append(word)

def create_dictionary(clean_word_list):
    word_count = {}
    for word in clean_word_list:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1

    for word, count in sorted(word_count.items(), key=operator.itemgetter(1)):
        print(word, count)
#
#start('https://buckysroom.org/tops.php?type=text&period=this-month')
if __name__ == "__main__":
    #countWordsInTxt(sys.argv[1])
    countWordsInAllFilesUnderDir(sys.argv[1])
