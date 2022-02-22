#makefile

vectorops.o: ernsts_vector_ops.cpp ernsts_vector_ops.hpp
	gcc -o vectorops $^

lab1stats.o: ernsts_stats.cpp ernsts_stats.hpp ernsts_stats_test.cpp
	g++ -o cppstats $^

all: vectorops.o

clean: 
	rm *.c *.o all