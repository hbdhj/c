#!/bin/bash
for file in `git status -s | grep "^[A|M]" | awk '{print $2}'`; 
do
    ext="${file##*.}"
    if [ "$ext" == "cpp" ]; then
        echo "We are going to check the source file - "$file
        /Users/denghaijun/Documents/github_stars/styleguide/cpplint/cpplint.py $file
        if [ $? != 0 ]; then
            exit 1
        else
            echo $file passed google cpplint check!
        fi
    fi
done
