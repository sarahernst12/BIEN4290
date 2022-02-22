/*
* date created: 2/21/22
* creator: sarah ernst
* description: pre processing data
*/

#include "ernsts_pre_processing.hpp"
#include "ernsts_stats.hpp"
#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <filesystem>

//creating stream for file opening
std::ifstream openedfile;

int main(int argc, char* argv[]){
    //what is the point of this??
    float m1, m2;
    ernsts::lab1 test(m1, m2);

    //getting red name file
    std::cout <<"Please input file name containing sporulating cells (red): ";
    std::string filenamered;
    std::cin >> filenamered;
    if(std::exists(filenamered))

    //getting red data
    std::cout <<"Please input file name containing red data: ";
    std::string filedatared;
    std::cin >> filedatared;

    //getting green name file
    std::cout <<"Please input file name non-sporulating cells (green): ";
    std::string filenamegreen;
    std::cin >> filenamegreen;
    
    //getting green data
    std::cout <<"Please input file name containing green data: ";
    std::string filedatagreen;
    std::cin >> filedatagreen;

    //name of file data will be written
    std::cout <<"Please input file name where calibrated data will be written: ";
    std::string filedatagreen;
    std::cin >> filedatagreen;

    //number of genes to be analyzed
    std::cout <<"Please input number of genes to be analyzed: ";
    double genenumber;
    std::cin >> genenumber;

    //opening files
    openedfile.open(filenamered);

}

