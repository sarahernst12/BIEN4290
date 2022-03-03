#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
#CFLAGS = -fpic -g

ernsts_stats.o: /home/ernsts/BIEN4290/Lab2/ernsts_stats.cpp
	g++ -c $^

ernsts_vector_ops.o: /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.cpp
	g++ -c $^
	
pre_processing: /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing.cpp /home/ernsts/BIEN4290/Lab2/ernsts_preproc_test.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o
	g++ -o $@ $^

#ernsts_preProc: /home/ernsts/BIEN4290/Lab2/ernsts_preproc_test.o /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o /home/ernsts/BIEN4290/Lab2/ernsts_stats.o
#	g++ -o $@ $^

#ernsts_k_means: /home/ernsts/BIEN4290/Lab2/ernsts_k_means.cpp /home/ernsts/BIEN4290/Lab2/ernsts_k_means.hpp
#	g++ -o $@ $^

ernsts_clusters.o: /home/ernsts/BIEN4290/Lab2/ernsts_k_means.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.o 
	g++ -o $@ $^

all: /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o /home/ernsts/BIEN4290/Lab2/pre_processing #/home/ernsts/BIEN4290/Lab2/ernsts_clusters.o

clean: 
	rm -f *.o
	rm -f *.gch
