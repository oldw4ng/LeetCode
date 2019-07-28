#!/bin/bash

target="README.md"

function insert() {
    pathname=$1
    filename=${pathname%.*}
    filename=${filename#*/}
    arr=(${filename//-/ })
    num=${arr[0]}
    title=""
    for ((i=1;i<${#arr[@]};i++)) do
        temp=${arr[i]^}
        title="$title$temp "
    done;
    quary="| $num | [$title](code/$pathname) |"
    echo $quary >> $target
}

> target
echo "# LeetCode

|No.|Title|
| - | - |" >> $target

filelist=`ls code/ | sort -n`
filearr=(${filelist})
for((j=0;j<${#filearr[@]};j++)) do
    insert ${filearr[j]}
done;