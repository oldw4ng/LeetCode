#!/bin/bash

target="README.md"

function insert() {
    pathname=$1
    num=${pathname%%.*}

    title=`sed -n 4p code/$pathname`
    title=${title#*]}


    quary="| $num | [$title](code/$pathname) |"
    echo $quary >> $target
}

> $target
echo "# LeetCode

|No.|Title|
| - | - |" >> $target

filelist=`ls code/ | sort -n`
filearr=(${filelist})
for((j=0;j<${#filearr[@]};j++)) do
    insert ${filearr[j]}
done;