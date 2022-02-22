#makefile

# $@ .... name of target
# $^ ... list of dependencies

ernsts_stats.o: ernsts_stats.cpp ernsts_stats.hpp
	g++ -c $^

ernsts_vector_ops.o: ernsts_vector_ops.cpp ernsts_vector_ops.hpp
	g++ -c $^

#ernsts_pre_processing.o: ernsts_pre_processing.cpp ernsts_pre_processing.hpp ernsts_stats.o ernsts_vector_ops.o

#	g++ -c $@ $^

#all: ernsts_pre_processing.o

clean: 
	rm -f *.o
	rm -f *.gch
