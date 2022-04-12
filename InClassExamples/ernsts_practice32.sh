#!/bin/bash
# creator: sarah ernst
# date: 3/2/22
# this is a script downloading files from github and determining namespace/functions and classes


wget -N https://raw.githubusercontent.com/sarahernst12/BIEN4290/master/Lab1/ernsts_stats.cpp

#function headers
grep ".*::.*(" < ernsts_stats.cpp > practice.txt

 
echo "namespace:" >> practice.txt
#add line to bottom of same file
grep ".*::" < ernsts_stats.cpp > practice.txt | sed 's/::.*//g'
#$practicedoc | sed 's/void ernsts::lab1:://'

# determining class of all functions
classname=$(grep -m1 "::.*" ./ernsts_stats.cpp | sed 's/.*::.*:://g')
# echo $classname



