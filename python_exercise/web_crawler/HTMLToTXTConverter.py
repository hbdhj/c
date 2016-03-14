from html.parser import HTMLParser
from urllib import parse

class HTMLToTXTConverter(HTMLParser):

    def __init__(self, ):
        super().__init__()
        self.txtString = ""
        self.pTag = False

    def error(self, message):
        pass

    def handle_starttag(self, tag, attrs):
        #print(tag)
        if tag == 'p':
            if len(attrs)==0:
                self.pTag = True

    def handle_data(self, data):
        if self.pTag:
            self.txtString += str(data) + '\n';

    def handle_endtag(self, tag):
        self.pTag = False

    def getText(self):
        return self.txtString

#finder =  LinkFinder()
#finder.feed("<html><head><title>Test</title></head>"
#            "<body><h1>parse me!</h1></body></html>")
