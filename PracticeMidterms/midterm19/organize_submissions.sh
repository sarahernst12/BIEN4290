#!/bin/bash
# sarah ernst
# 3/8/22

classlist=$1
input=$2
output=$3

#how to double check if arguments are inputted correctly
if [ $# -ne 3 ];
then
    echo "please enter 3 arguments"
    exit
fi

#getting directory name from input
baseDIR="$(dirname "${classlist}")"
tarDIR="$(dirname "${input}")"

#getting only file name from input
classlistname="$(basename "${classlist}")"
inputfilename="$(basename "${input}")"

#echo ${baseDIR}
#echo ${classlistname}
#echo ${tarDIR}
#echo ${inputfilename}

#double check both files exist
if [[ ! -e $input ]] 
then   
    echo "directory to $input does NOT exist"
    #exit 1
fi

if [[ ! -e $classlist ]]
then
    echo "directory to $classlist does NOT exist"
    #exit 1
fi

#create output dir if it doesn't exist
if [ ! -e $output ]
then
    mkdir $output
fi

#unpack tar archive
tar -xf ${input}

#copying all .c and .h files
cp *.c ${output}
cp *.h ${output}

for files in ${output}
do
    if [[ *"$files"* == *"$input"* ]]
    then
        echo "matching name $input found"
    fi
done

# while read -r line
# do
#     echo $line
# done < "$classlist"



# For each student in the class list: 
# while read students; do
#     # Unpack the tar archive
#     for f in ./test_data/*.tar.gz; do 
#         tar xf "$f"; 
#     done
#     # Copy each .c and .h file within the unpacked files into the out_directory
#     cp *.c *.h ./out_directory

#     # append the student’s last name to the start of the copied filename
#     mv ./out_directory/*.c ./out_directory/${students}_code.c
#     mv ./out_directory/*.h ./out_directory/${students}_code.h

# done <./test_data/class_list.txt