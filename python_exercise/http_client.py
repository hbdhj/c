import httplib

conn = httplib.HTTPConnection("localhost")
conn.request("GET", "/mysql_kb.php")

r1 = conn.getresponse()
print r1.status, r1.reason

data1 = r1.read()
print(data1)

conn.close()
