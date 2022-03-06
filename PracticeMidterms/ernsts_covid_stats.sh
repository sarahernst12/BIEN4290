#!/bin/bash
# creator: sarah ernst
# date: 3/6/22
# this script downloads latest data on COVID from website
# provides summary info to user

# 1st argument = header name for additional comparison stat
# $1
# 2nd argument = reference to country name
# 3rd argument = name of comparison country

#reference arguments as the following:
#echo "$1"
#echo "$2"
#echo "$3"

#download CSV file found here
#wget -N "https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv"
INPUT=owid-covid-data.csv
OLDIFS=$IFS
IFS=','

elemsum=0
#echo "$1"
#echo "$2"
#echo "$3"
#[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
while IFS=',' read -ra fields
do
    #skip header line
    #[[ "$iso_code" != "iso_code" ]] && echo "$name" && ((++count))
    #echo first three columns
    #echo ${fields[0]},${fields[1]},${fields[2]}
    #grep Bangladesh -A2
    country+=("${fields[1]}") #putting country names into array
    casepermil+=("${fields[11]}")
    #echo -e "${fields[2]},${fields[3]},${fields[11]}"
    #echo ${fields[11]}
    #echo $ar1    
done < $INPUT
IFS=$OLDIFS
#echo "${casepermil[@]}"

    # for i in "${casepermil[@]}"; do
    #     elemsum=$(echo $elemsum + $i | bc -l);
    # done
    # echo "Sum = ${elemsum}"
    len=${#casepermil[@]}
    sum=0.0
    for (( i=1; i<$len; i++ ));
    do 
         sum=$sum+${casepermil[i]}
    #     #sum=${casepermil[*]}
    #     #echo ${casepermil[$i]}
        
    done
    #sum=${casepermil[*]}
    #sum=$(IFS=+; echo"$(( ${sum[*]} ))" )
    echo "sum is : $sum" | bc -a

#echo -e "${fields[2]},${fields[3]},${fields[11]}"
# sum=0
# for sumnumber in $(echo -e "${fields[2]},${fields[3]},${fields[11]}")
# do
#     #sumnumber=${fields[11]}
#     sum=$sum+${fields[11]}
# done

# echo $sum


