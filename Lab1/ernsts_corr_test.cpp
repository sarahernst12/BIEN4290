/* 
* date created: 2/7/22
* creator: sarah ernst
* title: lab 1 correlation test cpp file 
* description: math to calculate correlation coefficient between two data sets
* references: 
*/


#include "ernsts_stats.hpp"
#include "ernsts_stats.cpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

//using namespace ernsts;

//creating stream for file opening
std::ifstream openedfile;

int main(int argc, char* argv[]){
    float m1, m2;
    ernsts::lab1 test(m1, m2);
    

    std::string filepath;

    std::cout <<"Please input path of input data file : ";
    std::string filename;
    std::cin >> filename;
    
    openedfile.open(filename);

    if(openedfile.is_open()){
        std::istream_iterator<float> start(openedfile), end;
        std::vector<float> data(start, end);
        int size = data.size();
        
    
    }
    
}
