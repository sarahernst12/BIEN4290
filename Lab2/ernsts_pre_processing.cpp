/*
* date created: 2/21/22
* creator: sarah ernst
* description: pre processing data
*/

#include "ernsts_pre_processing.hpp"
#include "ernsts_stats.hpp"
#include "ernsts_vector_ops.hpp"
#include <iostream> // header in standard library
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <filesystem>

//creating stream for file opening
std::ifstream red, redb, green, greenb, cali;

int main(int argc, char* argv[]){
    //what is the point of this??
    float m1, m2;
    ernsts::lab1 lab1(m1, m2);
    genome::lab2 lab2(m1, m2);

    std::vector<float> redcorrected;
    std::vector<float> greencorrected;

    //getting red name file
    std::cout <<"Please input file name containing data from sporulating cells (red): ";
    std::string filenamered;
    std::cin >> filenamered;
    red.open(filenamered);
    if(!red.is_open()){
        std::cout << "error: could not properly read red data file\n";
        return 1;
    }      

    //itereate through file from start to end
    std::istream_iterator<float> start(red), end;
    //put start and end of file into vector data
    std::vector<float> redcell(start, end);
    
    //get size of vector
    int sizered = redcell.size();
    red.close();

    //getting red data
    std::cout <<"Please input file name containing background red data: ";
    std::string filedatared;
    std::cin >> filedatared;
    redb.open(filedatared);
    if(!redb.is_open()){
        std::cout << "error: could not properly read red backgorund data file\n";
        return 1;
    }  
    //itereate through file from start to end
    std::istream_iterator<float> start(redb), end;
    //put start and end of file into vector data
    std::vector<float> backgroundred(start, end);
    //get size of vector
    int sizebackr = backgroundred.size();


    //getting green name file
    std::cout <<"Please input file name containing data from non-sporulating cells (green): ";
    std::string filenamegreen;
    std::cin >> filenamegreen;
    green.open(filenamegreen);
    if(!green.is_open()){
        std::cout << "error: could not properly read green data file\n";
        return 1;
    }  

    //itereate through file from start to end
    std::istream_iterator<float> start(green), end;
    //put start and end of file into vector data
    std::vector<float> greencell(start, end);
    //get size of vector
    int sizegreen = greencell.size();
    
    //getting green data
    std::cout <<"Please input file name containing background green data: ";
    std::string filedatagreen;
    std::cin >> filedatagreen;
    greenb.open(filedatagreen);
    if(!greenb.is_open()){
        std::cout << "error: could not properly read green background data file\n";
        return 1;
    }  
   
    //itereate through file from start to end
    std::istream_iterator<float> start(greenb), end;
    //put start and end of file into vector data
    std::vector<float> backgroundgreen(start, end);
    //get size of vector
    int sizebackg = backgroundgreen.size();

    //substracting background intensities from red datasets
    lab2.finddiff(redcell, backgroundred, redcorrected);

    //subtracting background intensitites from green datasets
    lab2.finddiff(greencell, backgroundgreen, greencorrected); 



    //name of file data will be written
    std::cout <<"Please input file name where calibrated data will be written: ";
    std::string filedatacali;
    std::cin >> filedatacali;
    cali.open(filedatacali);
    if(!cali.is_open()){
        std::cout << "error: could not properly read cali data file\n";
        return 1;
    }  


    //number of genes to be analyzed
    std::cout <<"Please input number of genes to be analyzed: ";
    double genenumber;
    std::cin >> genenumber;
    if(genenumber > sizered || genenumber > sizegreen){
        std::cout << "number of genes requested exceeds number of data points\n";
        return 1;
    }


}

