#!/bin/bash

cloc . > cloc_result.xml

lang_list=`head -23 cloc_result.xml | tail -15 | awk '{print "\x27" $1 "\x27" }'`
echo "var myLang = new Array("$lang_list");" >  hbdhj.github.io/resume/codeline_data.js

line_list=`head -23 cloc_result.xml | tail -15 | awk '{print $5}'`
echo "var myLines = new Array("$line_list");" >>  hbdhj.github.io/resume/codeline_data.js

rm cloc_result.xml

cd hbdhj.github.io
git add .
git commit -m "update at `date`"