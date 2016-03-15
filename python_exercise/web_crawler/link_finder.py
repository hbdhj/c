from html.parser import HTMLParser
from urllib import parse

class LinkFinder(HTMLParser):

    def __init__(self, base_url, page_url, ahref_class):
        super().__init__()
        print('base_url = '+base_url+', page_url = '+page_url)
        self.base_url = base_url
        self.page_url = page_url
        self.ahref_class = ahref_class

        self.links = set()

    def error(self, message):
        pass

    def handle_starttag(self, tag, attrs):
        #print(tag)
        if tag == 'a':
            classRight = False
            urlValue=""
            for (attribute, value) in  attrs:
                if attribute == 'class' and value == self.ahref_class:
                    classRight = True
                if attribute == 'href':
                    urlValue = value
            #print('url = '+urlValue)
            #if classRight and len(urlValue)>1 and urlValue.count('/')==1 and urlValue[0]=='/':
            if classRight and len(urlValue)>1 and urlValue.count('/')==2 and urlValue[0]=='/':
                url = parse.urljoin(self.base_url, urlValue)
                print('url = '+url)
                self.links.add(url)


    def page_links(self):
        return self.links

#finder =  LinkFinder()
#finder.feed("<html><head><title>Test</title></head>"
#            "<body><h1>parse me!</h1></body></html>")