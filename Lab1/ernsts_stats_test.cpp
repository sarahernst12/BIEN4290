/* 
* date created: 2/1/22
* creator: sarah ernst
* title: lab 1 stats cpp main file
* description: main function to call functions from hpp
* references: 
*/

#include "ernsts_stats.hpp"
#include "ernsts_stats.cpp"
//#include "ernsts_corr.cpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

//creating stream for file opening
std::ifstream openedfile;

int main(int argc, char* argv[]){
    //what is the point of this??
    float m1, m2;
    ernsts::lab1 test(m1, m2);

    //getting name of input file
    std::cout <<"Please input path of input data file : ";
    std::string filename;
    std::cin >> filename;
    
    //opening file
    openedfile.open(filename);

    //checking if file is open
    if(openedfile.is_open()){
        //itereate through file from start to end
        std::istream_iterator<float> start(openedfile), end;
        //put start and end of file into vector data
        std::vector<float> data(start, end);

        //get size of vector
        int size = data.size();

        //create temporary return variables for testing future function outputs to screen
        float maximum;
        float minimum; 
        float mean;
        float standarddev;
        std::vector<float> histogramdata{};

        //find max
        test.lab1::findmax(data);
        maximum = test.lab1::getmax();
        std::cout << "maximum is: " << maximum << "\n";

        //find min
        test.lab1::findmin(data);
        minimum = test.lab1::getmin();
        std::cout << "minimum is: " << minimum << "\n";

        //find mean
        test.lab1::findmean(data);
        mean = test.lab1::getmean();
        std::cout << "mean is " << mean <<"\n";

        //find standard dev
        test.lab1::findstandarddev(data);
        standarddev = test.lab1::getstandarddev();
        std::cout << "standard deviation is: " << standarddev << "\n";

        //print out histogram data -- CURRENTLY BROKEN 1/8
        test.findhistogram(data);
        histogramdata = test.gethistogram();
        std::cout << "the values of each bin are :\n";
        for(int i = 0; i < 15; i++){
            std::cout<< histogramdata[i] << "\n";
        }
    
    }
    else{
        std::cout << "error: could not properly read data file\n";
        return 1;
    }
    
}
