#!/bin/bash
# creator: sarah ernst
# date: 3/6/22
# this script automatically create a documentation file

# closer to difficulty of this year

input=$1

#taking off file extension from input
filename=$(echo "${input%%.*}")
#echo $filename

#creating output documentation file name
output="$filename"_documentation.txt
echo " output file: $output has been created "

#how to double check if # of arguments are inputted correctly
if [ $# -ne 1 ];
then
    echo "please enter only 1 hpp file"
    exit
fi

#double to see if file exists
if [ ! -e $input ]
then   
    echo "file: $input does NOT exist. please try again"
    exit 1
fi

#if output file exists, remove and restart
#delete output file if it exists (refresh output file)
if [ -e $output ]
then
    rm $output
fi

linenum=0
#linenum=1 when it's comment block description
#linenum=2 when it's class
#linenum=3 when it's a public function comment

while read -r line
do
    if [[ "$line" == "namespace"* ]]
    then
        linenum=2
    elif [[ "$line" == "/*"* ]]
    then
        linenum=1
    elif [[ "$line" == "public:" ]]
    then
        echo "PUBLIC ACCESS.........."
        linenum=3
    elif [[ "$line" == *"(*);"* ]]
    then
        linenum=3
    elif [[ "$line" == "protected:" ]]
    then
        echo "PROTECTED ACCESS.........."
        linenum=4
    elif [[ "$line" == "private:" ]]
    then
        echo "PRIVATE ACCESS.........."
        linenum=5
    elif [[ "$line" == "//"* ]] #non comment block
    then
        one=$(echo "$line" | sed -e "s/^[ ]*//")
        echo $one | sed -r 's/.{3}//'
    elif [[ "$linenum" == 2 ]]
    then
        echo "CLASS DESCRIPTOR ----------------------"
        echo ""
        linenum=0
    elif [[ "$linenum" == 1 ]]
    then    
        echo "COMMENT BLOCK DESCRIPTION ------------------------"
        echo ""
        linenum=0
    elif [[ "$linenum" == 3 ]]
    then
        echo "FUNCTION DESCRIPTION -----------------------------"
        echo ""
        linenum=0
    elif  [[ "$line" == "/*"* || "$line" == "*/"* || "$line" == "*"* ]] #comment block
    then
        echo "$line" | sed -r 's/.{2}//'
    fi


done < "$input"









# prevline=0
# while read -r line
# do
#     if [[ "$line" == "//"* || "$line" == "/*"* || "$line" == "*"* ]]
#     then
#         echo "$line" | grep -Po "^.{2}\K.*" | sed -e "s/^[ \t']*//" >> $output
#         prevline=1
#     elif [[ $prevline == 1 ]]
#     then
#         echo "--------------------------------" >> $output
#         prevline=0
#     else
#         prevline=0
#     fi
# done < "$input"
#echo $input | sed 's/ *$//g'



#echo "---------------CODE DESCRIPTION--------------------"
#grep "*" < $FILE
#grep "//" < $FILE

#cat $FILE | grep -n "/*" > $output
#cut comments.txt -d '*' -f 2

# while IFS= read -r line;
# do
#     #echo $fields > output.txt
#     #cut comments.txt -d '*' -f 2
#     myvar=$(echo $line | grep -- "//")
#     echo "$myvar"
# done < $FILE

#sed 's/* //g' > comments.txt

# while IFS='' read -ra fields
# do
#     country+=("${fields[1]}") #putting country names into array
#     date+=("${fields[3]}")
#     casepermil+=("${fields[11]}")
# done < $FILE


#---------------------
# first instance is presumably the description
# replace /* with another symbol to identify comments
# sed '0,/\/\*/{s//start_comment/}' ./test_data/$1 > ./modded_data.txt
# sed -i 's/\*\//end_comment/g' ./modded_data.txt

# # remove comment boundary strings
# sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' > output.txt

# echo "====================================================================================================" >> output.txt

# # remove boundaries surrounding description to avoid repeats
# sed -i '0,/start_comment/{s///}' ./modded_data.txt
# sed -i '0,/end_comment/{s///}' ./modded_data.txt

# # all instances of /* */ after are subsequent comment blocks for function definitions
# sed -i 's/\/\*/start_comment/g' ./modded_data.txt
# sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' | sed 's/\/\///' >> output.txt

# # removes trailing white spaces
# sed -i 's/^[ \t]*//;s/[ \t]*$//' output.txt


#-------------------solution
#extract and display to the console
# file=$1
# prevline=0
# while read -r line
# do
#     if [[ $line == //* || "$line"  == "/*"* || "$line" == "*"* ]] 
#     then
#         echo "$line" | grep -Po "^.{2}\K.*" | sed -e 's/^[ \t]*//' >> new.txt
#         prevline=1
#     elif [[ $prevline == 1 ]] 
#     then
#         echo "-------------------------------------" >> new.txt
#         prevline=0
#     else
#         prevline=0
#     fi

# done < "$file"