#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
CC = g++ -c
CFLAGS = -fPIC -g  #compiler flags

ernsts_stats.o: /home/ernsts/BIEN4290/MiniProjects/Mini_Project1/ernsts_MiniProject1.cpp 
	$(CC) $(CFLAGS) $^ -lm
	
libstats.so: ernsts_stats.o
	$(CC) -shared $^ -o 

all: libstats.so

clean: 
	rm -f *.o
	rm -f *.gch