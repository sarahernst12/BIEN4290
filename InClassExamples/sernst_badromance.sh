#!/bin/bash
# creator: sarah ernst
# date: 1/16/22
# this is a script about bash conditionals

lyrics1="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
lyrics2="Caught in a bad romance"
lyrics3="Ra-ra-ah-ah-ah"
lyrics4="Roma Roma-ma"
lyrics5="Gaga, Ooh la-la"
lyrics6="Want your bad romance"

for (( x=1;x<=6;x++ ));
do
    if [ $x -eq 1 ] || [ $x -eq 3 ];
    then
        echo "$lyrics1"
    elif [ $x -eq 2 ] || [ $x -eq 4 ];
    then    
        echo "$lyrics2"
    elif [ $x -eq 5 ] || [ $x -eq 9 ];
    then
        echo "$lyrics3"
    elif [ $x -eq 6 ] || [ $x -eq 10 ];
    then
        echo "$lyrics4"
        elif [ $x -eq 7 ] || [ $x -eq 11 ];
    then
        echo "$lyrics5"
    elif [ $x -eq 8 ] || [ $x -eq 12 ];
    then
        echo "$lyrics6"
    fi
done
