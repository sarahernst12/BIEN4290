/*
* date created: 3/1/22
* creator: sarah ernst
* description: pre processing data
*/

#include "ernsts_pre_processing.hpp"
#include "ernsts_k_means.hpp"
#include "ernsts_vector_ops.hpp"
#include "ernsts_stats.hpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <math.h>

//creating stream for file opening
std::ifstream red, redb, green, greenb;
std::ofstream cali;    

int main(int argc, char* argv[]){
    //what is the point of this??
    float m1 = 0, m2 = 0;
    ernsts::lab1 lab1(m1, m2);
    genome::lab2 lab2(m1,m2);
    genomep::preproc preproc;

    std::vector<float> redcorrected, rednormal;
    std::vector<float> greencorrected, greennormal;
    std::vector<float> logratio;

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
    std::istream_iterator<float> startr(red), endr;
    //put start and end of file into vector data
    std::vector<float> redcell(startr, endr);
    
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
    std::istream_iterator<float> startrb(redb), endrb;
    //put start and end of file into vector data
    std::vector<float> backgroundred(startrb, endrb);
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
    std::istream_iterator<float> startg(green), endg;
    //put start and end of file into vector data
    std::vector<float> greencell(startg, endg);
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
    std::istream_iterator<float> startgb(greenb), endgb;
    //put start and end of file into vector data
    std::vector<float> backgroundgreen(startgb, endgb);
    //get size of vector
    int sizebackg = backgroundgreen.size();

    //-------------------------------------
    // doing preprocessing 
    //-------------------------------------

    //substracting background intensities from red datasets
    lab2.finddiff(redcell, backgroundred, redcorrected);
    //subtracting background intensitites from green datasets
    lab2.finddiff(greencell, backgroundgreen, greencorrected); 

    //finding means of corrected datasets
    lab1.findmean(redcorrected);
    float redmean = lab1.getmean();
    lab1.findmean(greencorrected);
    float greenmean = lab1.getmean();

    //normalize corrected green data by green dataset mean
    lab2.finddivide(redcorrected, rednormal, redmean); 
    lab2.finddivide(greencorrected, greennormal, greenmean); 
    
    //find log ratio
    preproc.logratio(rednormal, greennormal, logratio);

    //name of file data will be written
    std::cout <<"Please input file name where calibrated data will be written: ";
    std::string filedatacali;
    std::cin >> filedatacali;
    cali.open(filedatacali);
    if(!cali.is_open()){
        std::cout << "error: could not properly read cali data file\n";
        return 1;
    }  

    //print logratio to cali data file
    for(int i = 0; i < logratio.size(); i++){
        cali << logratio[i] << "\n";
    }

    cali.close();


    //number of genes to be analyzed
    std::cout <<"Please input number of genes to be analyzed: ";
    double genenumber;
    std::cin >> genenumber;
    if(genenumber > sizered || genenumber > sizegreen){
        std::cout << "number of genes requested exceeds number of data points\n";
        return 1;
    }


    return 0;
}