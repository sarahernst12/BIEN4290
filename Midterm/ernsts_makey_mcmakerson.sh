#!/bin/bash
# sarah ernst
# 3/8/22

input=$1

#how to double check if arguments are inputted correctly
if [ $# -ne 1 ];
then
    echo "please enter 1 directory names"
    exit
fi

#getting directory name from input
fullpath="$(dirname "${input}")"

#getting only file name from input
directoryname="$(basename "${input}")"

#echo ${fullpath}
#echo ${directoryname}

#double check input file exist
if [ ! -e $input ]
then   
    echo "directory to $input does NOT exist"
    exit 1
fi

#make the Makefile 
#delete output file if it exists (refresh output file)
if [ -e $input/Makefile ]
then
    rm $input/Makefile
fi

touch $input/Makefile
#STARTING MAKEFILE
tab=' \t'
echo "CC = g++" >> $input/Makefile
echo "" >> $input/Makefile

# echo "cpp files: ------------------"

#cppfiles=$(find ${input}/ -name '*.cpp')
#cppfiles=$(echo "$cppfiles" | sed 's/\n/ /')
#echo $cppfiles

#TRYING TO SEPARATE # OF CPP FILES BY SPACE TO GET EACH FILE
cppfilenames=$(for cppfiles in ${input}/*.cpp;
do
    echo "$( basename "$cppfiles")"
done)

#echo $cppfilenames
cppnames=( $cppfilenames )
len=${#cppnames[@]}
echo $len

for((i=1;i<$len;i++))
do
    if [[ $i -le $len ]]
    then
        title=$(echo ${cppnames[$i]} | sed 's/cpp/o:/')
        line=$(echo "$title $cppfilenames" | sed 's/\n//')
        echo $line >> $input/Makefile
        echo -e "${tab}g++ -c $^" >> $input/Makefile
        echo "" >> $input/Makefile
        let i=$i+1
    fi
    
done


#TRYING TO SEPARATE # OF CPP FILES BY SPACE TO GET EACH FILE
# IFS=' '
# read -ra cpparr <<< "$cppfilenames"
# while IFS=' ' read -ra cppname
# do
#     #echo $cppname
# done < "$cppfilenames"

#echo "hpp files: ------------------"
#echo "${hppfiles[@]}"

hppfilenames=$(for hppfiles in ${input}/*.hpp;
do
    echo "$( basename "$hppfiles")"
done)
echo $hppfilenames


# echo "------------------------"
# echo "files containing main: "
main="main"
#figure out which files contain a main
mainfile=$(grep -rn $input/ -e "$main")

#error check if main does not exist

all="$@"
#echo $mainfile
mainname="$(basename "${mainfile}")"
#cleaning line up of everything else to find file name
maincppname=${mainname%:*:*}
maintitle=$(echo "$maincppname" | sed 's/.cpp/:/' | sed 's/\n//')
line=$(echo "$maintitle $cppfilenames" | sed 's/\n//')
echo $line >> $input/Makefile
echo -e "${tab}g++ -o $all" >> $input/Makefile
echo "" >> $input/Makefile


#doing end of stuff
echo "" >> $input/Makefile
echo "clean:" >> $input/Makefile
tab=' \t '
echo -e "${tab}rm -f *.o" >> $input/Makefile
echo -e "${tab}rm -f *.gch" >> $input/Makefile

#echo $("$maincppname" | sed 's/cpp/o:/') >> Makefile
