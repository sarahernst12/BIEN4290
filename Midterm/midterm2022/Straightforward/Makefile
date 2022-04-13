CC = g++

toss_a_coin.o: dandelion.cpp toss_a_coin.cpp valley_of_plenty.cpp wolf.cpp
 	g++ -c $^

wolf.o: dandelion.cpp toss_a_coin.cpp valley_of_plenty.cpp wolf.cpp
 	g++ -c $^

dandelion.o: dandelion.cpp
toss_a_coin.cpp
valley_of_plenty.cpp
wolf.cpp

clean:
 	 rm -f *.o
 	 rm -f *.gch
