#!/bin/bash
for file in `git status -s | grep "^[A|M]" | awk '{print $2}'`; 
do
    ext="${file##*.}"
    if [ "$ext" == "py" ]; then
        echo "We are going to check the source file - "$file
        pep8 $file
        if [ $? != 0 ]; then
            exit 1
        else
            echo $file" passed pep8 check"
        fi
    fi
done
