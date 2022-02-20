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
let x=2

while [$x -gt 0]
do
    echo "$lyrics1"
    echo "$lyrics2"
    let x=x-1
done


