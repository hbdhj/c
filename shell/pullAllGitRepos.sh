#/bin/bash
for dir in `find . -type d -name ".git"`
do
    #echo $dir
    sub_dir="${dir:0:${#dir}-4}"
    cd $sub_dir
    echo "================== Updating "$sub_dir" =================="
    git pull
    cd -
done
