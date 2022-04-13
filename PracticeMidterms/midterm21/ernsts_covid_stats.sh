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

comparison="$1"
country1="$2"
country2="$3"

echo "the first country you are looking for is: $country1"

while IFS=',' read -ra fields
do
    #test=$(echo "${fields[2]}" | grep -r "$country1")
    #echo $test >> country1list.txt
    #countrylist1+=$( echo "${fields[2]}" | grep "$country1" -c) #putting country names into array
    #date+=("${fields[3]}")
    #casepermil+=("${fields[11]}")
    #country1=$(echo ${fields[1]} | grep "$country1" -c)
    #country2=$(echo ${fields[1]} | grep "$country2" -c)
    if [[ ${fields} == *"$country1"* ]]
    then
        echo ${fields}
    done

done < $INPUT

len=${#country[@]}
sum=0

#echo ${countrylist1[@]}

# for((i=0;i<=$len;i++)); do
#     #echo ${country1[$i]},${country2[$i]}
#     findcountry1=$(echo "${fields[1]}" | grep "$country1" -c)

#     if [[ $findcountry1 -ne 0 ]]
#     #interested in counting rolling total - so i want to keep track of number
#     then
#         echo "$total+$findcountry1= ?"
#         total=$(echo "$total+$findcountry1" | bc -l)
#         echo "$total"
#     fi

#     #sum=$(echo "$sum+${casepermil[$i]}" | bc -l)
# done
# echo "there are $total total $findcountry1 in captains names"

#         # if [ ${date[$i]} -eq 2 ];
#         # then
#         #     echo -e ${country[$i]},${date[$i]},${casepermil[$i]}
#         # fi
#         #sum=$sum+${casepermil[$i]}
#         if [[ "${country[@]}" = "Angola" ]];
#         then
#             echo "${date[$i]}" | grep '2022-02'
#         fi



# elemsum=0
# #echo "$1"
# #echo "$2"
# #echo "$3"
# #[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }


#     while IFS=',' read -ra fields
#     do
#         #skip header line
#         #[[ "$iso_code" != "iso_code" ]] && echo "$name" && ((++count))
#         #echo first three columns
#         #echo ${fields[0]},${fields[1]},${fields[2]}
#         #grep Bangladesh -A2
#         country+=("${fields[1]}") #putting country names into array
#         date+=("${fields[3]}")
#         casepermil+=("${fields[11]}")
#         #echo -e "${fields[2]},${fields[3]},${fields[11]}"
#         #echo ${fields[11]}
#         #echo $ar1    
#     done < $INPUT
# IFS=$OLDIFS
# #echo "${casepermil[@]}"

#     len=${#casepermil[@]}
    
#     sum=0.0
#     a=4.5
#     #echo "$a + $b" | bc -l
#     for (( i=1; i<$len; i++ ));
#     do
#         # if [ ${date[$i]} -eq 2 ];
#         # then
#         #     echo -e ${country[$i]},${date[$i]},${casepermil[$i]}
#         # fi
#         #sum=$sum+${casepermil[$i]}
#         if [[ "${country[@]}" = "Angola" ]];
#         then
#             echo "${date[$i]}" | grep '2022-02'
#         fi
        
#         #echo "$sum + ${casepermil[$i]}" | bc -l
#     done

    


    #do
    #    sum+=${casepermil[$i]}
        #echo "$sum + ${casepermil[$i]}" | bc -l
    #     #sum=${casepermil[*]}
    #     #echo ${casepermil[$i]}
    #done
    #    echo $sum | bc -l

    #sum=${casepermil[*]}
    #sum=$(IFS=+; echo"$(( ${sum[*]} ))" )
    #echo "$sum" | bc -l




#echo -e "${fields[2]},${fields[3]},${fields[11]}"
# sum=0
# for sumnumber in $(echo -e "${fields[2]},${fields[3]},${fields[11]}")
# do
#     #sumnumber=${fields[11]}
#     sum=$sum+${fields[11]}
# done

# echo $sum


