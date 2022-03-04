#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
#CFLAGS = -fpic -g

ernsts_stats.o: /home/ernsts/BIEN4290/Lab2/ernsts_stats.cpp
	g++ -c $^

ernsts_vector_ops.o: /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.cpp
	g++ -c $^

#run exe with the following arguments:
# /lab/bien4290/microarray/red_0.dat /lab/bien4290/microarray/red_background_0.dat /lab/bien4290/microarray/green_0.dat /lab/bien4290/microarray/green_background_0.dat /home/ernsts/BIEN4290/Lab2/log_ratio_input.dat 600
# or whichever "red_X.dat" etc. you wish
pre_processing: /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing.cpp /home/ernsts/BIEN4290/Lab2/ernsts_preproc_test.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o
	g++ -o $@ $^

#must do this individually to fully work
#run exe with the following arguments: 
# /home/ernsts/BIEN4290/Lab2/log_ratio_input.dat /home/ernsts/BIEN4290/Lab2/suppressed_data.txt /home/ernsts/BIEN4290/Lab2/stationary_data.txt /home/ernsts/BIEN4290/Lab2/expressed_data.txt
ernsts_clusters: /home/ernsts/BIEN4290/Lab2/ernsts_k_means.cpp /home/ernsts/BIEN4290/Lab2/ernsts_clusters.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o 
	g++ -o $@ $^

all: /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o /home/ernsts/BIEN4290/Lab2/pre_processing #/home/ernsts/BIEN4290/Lab2/ernsts_clusters

clean: 
	rm -f *.o
	rm -f *.gch
