#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
#CFLAGS = -fpic -g

ernsts_stats.o: /home/ernsts/BIEN4290/Lab2/ernsts_stats.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.hpp
	g++ -c $^

ernsts_vector_ops.o: /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.cpp /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.hpp
	g++ -c $^

ernsts_pre_processing: /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing.cpp /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o
	g++ -o $@ $^

ernsts_k_means: /home/ernsts/BIEN4290/Lab2/ernsts_k_means.cpp /home/ernsts/BIEN4290/Lab2/ernsts_k_means.hpp
	g++ -o $@ $^

ernsts_vector_exe: /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing.o 
	g++ -o $@ $^

all: /home/ernsts/BIEN4290/Lab2/ernsts_pre_processing /home/ernsts/BIEN4290/Lab2/ernsts_stats.o /home/ernsts/BIEN4290/Lab2/ernsts_vector_ops.o

clean: 
	rm -f *.o
	rm -f *.gch
