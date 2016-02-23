#!/usr/bin/python
import os
#import smtplib
import subprocess

#content = str(os.system('df -h /'))
#print (content)
#p = subprocess.Popen(['df', '-h /'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
#out, err = p.communicate()
#out=iter(p.stdout.readline, b'')
#for line in out:
#	print(line)
out = subprocess.Popen(['df', '-h'], stdout=subprocess.PIPE).communicate()[0]
print(out)
