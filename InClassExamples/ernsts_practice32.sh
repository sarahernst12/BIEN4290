#!/bin/bash
# creator: sarah ernst
# date: 3/2/22
# this is a script downloading files from github and determining namespace/functions and classes


wget -N https://raw.githubusercontent.com/sarahernst12/BIEN4290/master/Lab1/ernsts_stats.cpp

grep "ernsts::lab1::" < ernsts_stats.cpp > practice.txt
practicedoc='cat practice.txt'
$practicedoc | sed 's/void ernsts::lab1:://'



