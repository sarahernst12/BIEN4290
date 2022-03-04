#!/bin/bash
# sarah ernst
# 3/1/22
# prompt user for number of microarray points to be read & calibrate/cluster data 

#make all

echo "Enter # of microarray points to be read: "
read microarraynum;

if [ ${microarraynum} -ne 6118 ]
then
    echo "Invalid number of microarray points. Please try again"
    exit 1
fi

# calibrate data from each of 7 time points
# preprocessed data should be written to 7 different output files
#log_ratio__input_0.dat
#log_ratio_input_1.dat
#log_ratio_input_2.dat
#log_ratio_input_3.dat
#log_ratio_input_4.dat
#log_ratio_input_5.dat
#log_ratio_input_6.dat

for i in {0..6}; do
    ./pre_processing /lab/bien4290/microarray/red_$i.dat /lab/bien4290/microarray/red_background_$i.dat /lab/bien4290/microarray/green_$i.dat /lab/bien4290/microarray/green_background_$i.dat /home/ernsts/BIEN4290/Lab2/log_ratio_input_$i.dat $microarraynum

    #script should copy logratio output data to new file
    cp /home/ernsts/BIEN4290/Lab2/log_ratio_input_$i.dat /home/ernsts/BIEN4290/Lab2/log_ratio_input.dat 
    
    echo "Time Point #$i: " >> "summarydata.txt"
    
    #run clustering program
    ./ernsts_clusters /home/ernsts/BIEN4290/Lab2/log_ratio_input_$i.dat /home/ernsts/BIEN4290/Lab2/suppressed_data$i.txt /home/ernsts/BIEN4290/Lab2/stationary_data$i.txt /home/ernsts/BIEN4290/Lab2/expressed_data$i.txt >> /home/ernsts/BIEN4290/Lab2/summarydata.txt

    #copy cluster output files to files whose names denote corresponding time point
    #create summary file that lists final cluster means, total number of exp, suppr,stat. genes for each time point

    echo "Number of suppressed data points: " >> "summarydata.txt"
    wc -l < suppressed_data$i.txt >> /home/ernsts/BIEN4290/Lab2/summarydata.txt

    echo "Number of stationary data points: " >> "summarydata.txt"
    wc -l < stationary_data$i.txt >> /home/ernsts/BIEN4290/Lab2/summarydata.txt

    echo "Number of expressed data points: " >> "summarydata.txt"
    wc -l < expressed_data$i.txt >> /home/ernsts/BIEN4290/Lab2/summarydata.txt
    
done
