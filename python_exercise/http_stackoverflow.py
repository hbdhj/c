#python 2.7

import httplib
from HTMLParser import HTMLParser
#import xml.dom.minidom

conn = httplib.HTTPConnection("stackoverflow.com")
conn.request("GET", "/questions?pagesize=50&sort=newest")

r1 = conn.getresponse()
print r1.status, r1.reason

data1 = r1.read()
#print(data1)

conn.close()

class MyHTMLParser(HTMLParser):
    got = False
    tag_dict={}

    def handle_starttag(self, tag, attrs):
        #print "Start tag:", tag
        if tag=="a":
            for attr in attrs:
                #print "     attr:", attr
                if attr[0]=="class" and attr[1]=="post-tag":
                    self.got = True
    def handle_endtag(self, tag):
        pass
        #print "End tag  :", tag
    def handle_data(self, data):
        #print "Data     :", data
        if self.got:
            #print "**** Data: ", data
            if data in self.tag_dict:
                self.tag_dict[data]+=1
            else:
                self.tag_dict[data]=1
            self.got = False
    def handle_comment(self, data):
        pass
        #print "Comment  :", data
    def handle_entityref(self, name):
        try:
            c = unichr(name2codepoint[name])
        except Exception as err:
            #print(err)
            #print(name)
            pass
    def handle_charref(self, name):
        if name.startswith('x'):
            c = unichr(int(name[1:], 16))
        else:
            c = unichr(int(name))
        #print "Num ent  :", c
    def handle_decl(self, data):
        pass
        #print "Decl     :", data

parser = MyHTMLParser()
parser.feed(data1)
#print parser.tag_dict

items = parser.tag_dict.items()
items.sort()
backitems=[[v[1],v[0]] for v in items]
backitems.sort()
print backitems
print [v[1] for v in backitems]

#<a href="/questions/tagged/ruby-on-rails" class="post-tag"
#title="show questions tagged &#39;ruby-on-rails&#39;" rel="tag">ruby-on-rails</a>
'''
dom = xml.dom.minidom.parseString(data1)
hyperLinks=dom.getElementsByTagName("a")
for hyperLink in hyperLinks:
    print(hyperLink.getAttribute("class"))
    print(hyperLink.nodeValue())
'''
