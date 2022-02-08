/* 
* date created: 2/7/22
* creator: sarah ernst
* title: lab 1 correlation test cpp file 
* description: math to calculate correlation coefficient between two data sets
* references: 
*/


#include "ernsts_stats.hpp"
#include "ernsts_corr.hpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

//using namespace ernsts;

//creating stream for file opening
std::ifstream openedfilex;
std::ifstream openedfiley;


int main(int argc, char* argv[]){
    ernstscorr::lab1corr tester;

    std::string filex, filey;

    //handling file x for comparison
    std::cout <<"Please input path of input data file 1 : ";
    std::string filenamex;
    std::cin >> filenamex;
    openedfilex.open(filenamex);

    //handling file y for comparison
    std::cout <<"Please input path of input data file 2: ";
    std::string filenamey;
    std::cin >> filenamey;
    openedfiley.open(filenamey);

    float correlation;

    if((openedfilex.is_open()) && (openedfiley.is_open())){
        std::istream_iterator<float> startx(openedfilex), endx;
        std::vector<float> datax(startx, endx);
        //int sizex = datax.size();

        std::istream_iterator<float> starty(openedfiley), endy;
        std::vector<float> datay(starty, endy);
        //int sizey = datay.size();

        //print out correlation value
        tester.findcorrelation(datax, datay);
        correlation = tester.getcorrelation();
        std::cout << correlation << "\n"; //printing correlation value
    
    }
    else{
        std::cout << "error: could not properly read data files\n";
        return 1;
    }
    
}
