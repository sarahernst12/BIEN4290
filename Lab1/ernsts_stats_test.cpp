/* 
* date created: 2/1/22
* creator: sarah ernst
* title: lab 1 stats cpp main file
* description: main function to call functions from hpp
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
        test.findmean(data);
        mean = test.getmean();
        std::cout << "mean is " << mean <<"\n";

        //find standard dev
        test.findstandarddev(data);
        standarddev = test.getstandarddev();
        std::cout << "standard deviation is: " << standarddev << "\n";

        //print out histogram data
        test.findhistogram(data);
        histogramdata = test.gethistogram();
        std::cout << "the values of each bin are :\n";
        for(int i = 0; i < size; i++){
            std::cout<< histogramdata[i] << "\n";
        }
    
    }

    
    
}
