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