#!/bin/bash
# sarah ernst
# 3/1/22
# gene query -- take commandline arg the gene name

echo "Which gene status would you like?"
read genestatus

#output to screen the status of the gene for each time point
#status either:expressed, suppressed, stationary

for i in {0..6}
do
    if grep -Fq "$genestatus" suppressed_data$i.txt
    then
        echo "Gene is Suppressed at time: $i"
    elif grep -Fq "$genestatus" stationary_data$i.txt
    then
        echo "Gene is Stationary at time: $i"
    elif grep -Fq "$genestatus" expressed_data$i.txt
    then
        echo "Gene is Expressed at time: $i"
    else
        echo "Gene at time $i cannot be found."
    fi
done

    