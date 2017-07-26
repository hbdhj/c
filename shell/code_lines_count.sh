#!/bin/bash

cloc . > cloc_result.xml

echo "// update at `date`" > codeline_data.js

lang_list=`head -23 cloc_result.xml | tail -15 | awk '{print "\x27" $1 "\x27" "\x2c" }'`
echo "var myLang = new Array("$lang_list");" >>  codeline_data.js

line_list=`head -23 cloc_result.xml | tail -15 | awk '{print $5 "\x2c"}'`
echo "var myLines = new Array("$line_list");" >>  codeline_data.js

#rm cloc_result.xml

diff codeline_data.js hbdhj.github.io/resume/codeline_data.js
if [ $? -eq 1 ]; then
	cp codeline_data.js hbdhj.github.io/resume/codeline_data.js
	cd hbdhj.github.io
	git add .
	if [ $? -eq 0 ]; then
		git commit -m "update at `date`"
	fi
fi
