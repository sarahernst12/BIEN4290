#makefile

# $@ .... name of target
# $^ ... list of dependencies

ernsts_stats.o: ernsts_stats.cpp ernsts_stats.hpp
	g++ -c cppstats $^

ernsts_vector_ops.o: ernsts_vector_ops.cpp ernsts_vector_ops.hpp
	g++ -c vectorops $^

ernsts_pre_processing.o: ernsts_pre_processing.cpp ernsts_pre_processing.hpp ernsts_stats.cpp  ernsts_stats.hpp ernsts_vector_ops.cpp ernsts_vector_ops.hpp
	g++ -o preprocess $^

all: ernsts_vector_ops.o ernsts_stats.o ernsts_pre_processing.o

clean: 
	rm -f *.o
	rm -f *.gch
