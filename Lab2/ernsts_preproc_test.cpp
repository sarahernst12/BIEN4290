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
#include <stdio.h>
#include <stdlib.h>

//creating stream for file opening
std::ifstream red, redb, green, greenb;
std::ofstream cali;    

int main(int argc, char* argv[]){
    //what is the point of this??
    //constructors from other classes
    float m1 = 0, m2 = 0;
    ernsts::lab1 lab1(m1, m2);
    genome::lab2 lab2(m1,m2);
    genomep::preproc preproc;

    std::vector<float> redarray, redbarray, greenarray, greenbarray;

   // FILE *filenamered, filedatared, filenamegreen, filedatagreen, filedatacali;

    //getting red data
    //std::cout <<"Please input file name containing data from sporulating cells (red): ";
    std::string filenamered = argv[1];
    //getting red background file
    std::string filedatared = argv[2];
    //getting green name file
    //std::cout <<"Please input file name containing data from non-sporulating cells (green): ";
    std::string filenamegreen = argv[3];
    //getting green data
    //std::cout <<"Please input file name containing background green data: ";
    std::string filedatagreen = argv[4];
    //name of file data will be written
    //std::cout <<"Please input file name where calibrated data will be written (outputfilename): ";
    std::string filedatacali = argv[5];
    //number of genes to be analyzed
    //std::cout <<"Please input number of genes to be analyzed: ";
    std::string genenumber = argv[6];

    if(argc > 8){
        printf("number of arguments is incorrect. please try again.\n");
    }

    
    //OPENING RED SPORULATING DATA
    red.open(filenamered);
    if(!red.is_open()){
        std::cout << "error: could not properly read red data file\n";
        return 1;
    }      

    //itereate through file from start to end to read in data
    std::istream_iterator<float> startr(red), endr;
    //put start and end of file into vector data
    std::vector<float> redcell(startr, endr);

    //get size of vector
    int sizered = redcell.size();

    //double checking
    //std::cout << "size of red sporulating file is : " << sizered << " \n";
    
    //OPEN RED BACKGROUND DATA FILE
    redb.open(filedatared);
    if(!redb.is_open()){
        std::cout << "error: could not properly read red background data file\n";
        return 1;
    }  
    //itereate through file from start to end
    std::istream_iterator<float> startrb(redb), endrb;
    //put start and end of file into vector data
    std::vector<float> backgroundred(startrb, endrb);
    //get size of vector
    int sizebackr = backgroundred.size();

    //double checking
    //std::cout << "size of red BACKGROUND file is : " << sizebackr << " \n";

    //OPENING GREEN NON-SPORULATING DATA FILE
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
    
    //double checking
    //std::cout << "size of green non-sporulating file is : " << sizegreen << " \n";

    //OPENING GREEN BACKGROUND DATA FILE
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

    //double checking
    //std::cout << "size of green background data file is : " << sizebackg << " \n";

    //OPENING OUTPUT FILE
    //log_ratio_input.dat
    cali.open(filedatacali);
    if(!cali.is_open()){
        std::cout << "error: could not properly read output data file\n";
        return 1;
    }  

    //double checking
    //std::cout << "name of output file is: " << argv[5] << " \n\n";


    //-------------------------------------
    // doing preprocessing 
    //-------------------------------------
  

    //placeholder vectors for corrected and normalized data
    std::vector<float> redcorrected, rednormal;
    std::vector<float> greencorrected, greennormal;
    std::vector<float> logratio;

    //finding differences in datasets
    //subtracting background intensities from red datasets
    lab2.finddiff(&redcell, &backgroundred, &redcorrected);
    //subtracting background intensitites from green datasets
    lab2.finddiff(&greencell, &backgroundgreen, &greencorrected); 

  
    //finding means of corrected datasets
    //lab1.findmean(redcorrected);
    float redmean = lab1.getmean();
    //lab1.findmean(greencorrected);
    float greenmean = lab1.getmean();

    //returning means:
    //std::cout << "the mean for the red corrected data is: " << redmean << "\n";
    //std::cout << "the mean for the green corrected data is: " << greenmean << "\n\n";
    
    //normalize corrected green data by green dataset mean
    lab2.finddivide(&redcorrected, &rednormal, redmean); 
    lab2.finddivide(&greencorrected, &greennormal, greenmean); 

    //std::cout << "division of arrays are accurate! \n";
    
    //find log ratio
    preproc.logratio(&rednormal, &greennormal, &logratio);

    //std::cout << "logratio has been preformed!" << " \n";

    
    //print logratio to cali data file
    for(int i = 0; i < logratio.size(); i++){
        cali << logratio[i] << "\n";
    }

    //std::cout << "output file has been outputed!" << " \n";

    
    //handling number of genes // what do i do with this?? 
    int genenum = std::stoi(genenumber);
    if(genenum > sizered || genenum > sizegreen){
        std::cout << "number of genes requested exceeds number of data points\n";
        return 1;
    }
    

    red.close();
    redb.close();
    green.close();
    greenb.close();
    cali.close();
    

    std::cout << "you're allllllllll good hun! \n";
    return 0;
}