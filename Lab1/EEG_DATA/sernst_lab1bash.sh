#!/bin/bash

# name: sarah ernst
# date: 2/8/22
# shell scripting c++ algorithms to analyze EEG data in lab/BIEN4290/ERP

#prompt user for the concentrations level to analyze
echo "type your concentrations level to analyze: "
echo "TYPE ERP00 for 0.0% or ERP05 for 0.5%?"
read x
#return back concentration level for confirmation
#echo "your desired concentration level: ${x}"
cd $x
cat ERP0*.txt > /home/ernsts/BIEN4290/Lab1/EEG_DATA/$x/bigdatafile.dat
cp bigdatafile.dat /home/ernsts/BIEN4290/Lab1/EEG_DATA/$x/catted_input.dat
cd ~/bin
./statstest > /home/ernsts/BIEN4290/Lab1/EEG_DATA/output$x.txt
FILE="/home/ernsts/BIEN4290/Lab1/EEG_DATA/output$x.txt"
echo "-------------- File $FILE contents: --------------"
cat $FILE

#concentration stuff
FILECORR="/home/ernsts/BIEN4290/Lab1/EEG_DATA/$x"
one=1
two=2
end=".txt"
vs=" vs. "
cd ~/bin
./corrtest $FILECORR$one$end $FILECORR$two$end > /home/ernsts/BIEN4290/Lab1/EEG_DATA/correlation$x.txt
echo $one$vs$two >> /home/ernsts/BIEN4290/Lab1/EEG_DATA/correlation$x.txt

#use while loop to index through file
    while [ $one -le 58 ]
    do
        one=$((x+1))
        two=$((y+1))
        ./corrtest $first$one$end $first$two$end >> /home/ernsts/BIEN4290/Lab1/EEG_DATA/correlation$x.txt
        echo $one$vs$two >> /home/ernsts/BIEN4290/Lab1/EEG_DATA/correlation$x.txt
    done