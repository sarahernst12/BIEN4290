#makefile

# $@ .... name of target
# $^ ... list of dependencies

SHELL = /bin/bash 
CC = g++
CFLAGS = -fPIC -g  #compiler flags
LDFLAGS = -lm -lstats
LIBDIR = /home/ernsts/BIEN4290/Lab1
INCDIR = /home/ernsts/BIEN4290/Lab1

airspeed: /home/ernsts/BIEN4290/MiniProjects/Mini_Project1/ernsts_MiniProject1.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $< -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)
	./airspeed swallowspeed.dat

clean: 
	rm -f *.o
	rm -f *.gch