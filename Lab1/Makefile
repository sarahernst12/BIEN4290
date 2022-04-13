#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
CC = g++
CFLAGS = -fPIC -g  #compiler flags

ernsts_stats.o: /home/ernsts/BIEN4290/Lab1/ernsts_stats.cpp /home/ernsts/BIEN4290/Lab1/ernsts_stats.hpp
	$(CC) $(CFLAGS) -o $@ $< -lm
	
libstats.so: ernsts_stats.o
	$(CC) -shared $^ -o $@

all: libstats.so

clean: 
	rm -f *.o
	rm -f *.gch