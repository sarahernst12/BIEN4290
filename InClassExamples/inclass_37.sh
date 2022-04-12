#!/bin/bash
# creator: sarah ernst
# date: 3/7/22


#practicing read arrays
readarray -t caps < captains.txt

lookfor="r"
total=0

for((i=0;i<${#caps[@]};i++));
do
    #echo ${caps[$i]}
    howmany=$(echo ${caps[$i]} | grep "$lookfor" -c)

    if [[ $howmany -ne 0 ]]
    #interested in counting rolling total - so i want to keep track of number
    then
        echo "$total+$howmany= ?"
        total=$(echo "$total+$howmany" | bc -l)
        echo "$total"
    fi
done

echo "there are $total total $lookfor in captains names"