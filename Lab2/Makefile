#makefile
all: vectoropstats.exe 

vectoropstats: ernsts_vector_ops.o ernsts_stats.o 
	gcc -o vectoropstats.exe ernsts_vector_ops.o ernsts_stats.o -lm

clean: 
	rm *.c *.o all