#!/bin/bash

# name: sarah ernst
# date: 2/15/22
# analyzing EEG data with histogram

#prompt user for the concentrations level to analyze
echo "type your concentrations level to analyze: "
echo "TYPE ERP00 for 0.0% or ERP05 for 0.5%?"
read x

cd $x
#return back concentration level for confirmation
#echo "your desired concentration level: ${x}"
if [[ "$x" == "ERP00" ]];
then
    cat /home/ernsts/BIEN4290/Lab1/EEG_DATA/ERP00/* > /home/ernsts/BIEN4290/Lab1/EEG_DATA/catted_input.dat
elif [[ "$x" == "ERP05" ]];
then
    cat /home/ernsts/BIEN4290/Lab1/EEG_DATA/ERP05/* > /home/ernsts/BIEN4290/Lab1/EEG_DATA/catted_input.dat
fi

~/bin/./statstest /home/ernsts/BIEN4290/Lab1/EEG_DATA/catted_input.dat > /home/ernsts/BIEN4290/Lab1/EEG_DATA/histogram_$x.dat

#check if file exists
FILE=/home/ernsts/BIEN4290/Lab1/EEG_DATA/histogram_$x.dat

if [[ ! -e "$FILE" ]];
then
    echo "file does not exist. please try again"
fi

