# date created: 1/25/22
# creator: sarah ernst
# title: lab 0 part III
# description: bash script to output names of all files as well as total number of files to screen

#go to home directory
cd ~/ 

#print out number of files
printf "The number of files in your directory is: "

#use output of finding all files (ls -a) as input to counting all lines (wc -l)
ls -a | wc -l

#output names of all files
printf "The names of your files are: \n\n"
ls -a
