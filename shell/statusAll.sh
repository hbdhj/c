#!/bin/bash
# cd /Users/denghaijun/Documents/github
for folder in `ls`; do
	if [ -d $folder -a -d $folder/.git ]; then
		echo pull $folder
		cd $folder
		git status
		cd ..
	fi
done
