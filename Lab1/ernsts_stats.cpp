/* 
* date created: 2/1/22
* creator: sarah ernst
* title: lab 1 stats cpp main file
* description: main function to call functions from hpp
* references: 
*/

#include "ernsts_stats.hpp"
#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>

//using namespace ernsts;

ernsts::lab1::lab1(float min, float max){
    //setting all class variables
    this->minimumvalue;
    this->maximumvalue;
    this->meanvalue;
    this->standarddevvalue;
    std::vector<float> histogramvalue{};
}

void ernsts::lab1::findmin(std::vector<float> data) {
    //how to calculate minimum element of vector
    int size = data.size();

    float minimum;
    minimum = data[0];
    for (int i = 0; i < size; i++){
        if (data[i] < minimum){
            this->minimumvalue = data[i];
            minimum = data[i];
        }
        else{
            this->minimumvalue = minimum;
        }
    }
}

float ernsts::lab1::getmin(){
    return this->minimumvalue;
}

void ernsts::lab1::findmax(std::vector<float> data) {
    //write how to calculate max here
    int size = data.size();
    
    float maximum;
    maximum = data[0];
    for (int i = 0; i < size; i++){
        if (data[i] > maximum){
            this->maximumvalue = data[i];
            maximum = data[i];
        }
    }
}

float ernsts::lab1::getmax(){
    return this->maximumvalue;
}

void ernsts::lab1::findmean(std::vector<float> data) {
    //write how to calculate mean here
    int size = data.size();

    float sum;
    for(int i = 0; i < size; i++){
        sum = sum + data[i];
    }

    this->meanvalue = sum / size;
}

float ernsts::lab1::getmean() {
    return this->meanvalue;
}

void ernsts::lab1::findstandarddev(std::vector<float> data) {
    //write how to calculate standarddev here
    int size = data.size();

    float standarddev;

    for(int i = 0; i < size; i++){
        standarddev += pow(data[i] - this->meanvalue, 2); //sum of the squares
    }

    standarddev = standarddev / (size - 1);

    standarddev = sqrt(standarddev);

    this->standarddevvalue = standarddev;

}

float ernsts::lab1::getstandarddev(){
    return this->standarddevvalue;
}

void ernsts::lab1::findhistogram(std::vector<float> data){
    //write how to calculate histogram here
    int size = data.size();
    float binlow, binhigh, samplemean;
    float binwidth = 0.4 * (this->standarddevvalue);
    std::vector<float> histogramdata{0}; 
    
    for(int i = 0; i < size; i++){
        
        
        binlow = this->meanvalue - (3 * this->standarddevvalue);
        binhigh = this->meanvalue - (3 * this->standarddevvalue);

        //bin 1
        if(data[i] >= binlow && data[i] < (binlow+binwidth)){
            histogramdata[0]++;
        }
        //bin 2
        else if(data[i] >= (binlow + binwidth) && data[i] < (binlow + (2*binwidth))){
            histogramdata[1]++;
        }
        //bin 3
        else if(data[i] >= (binlow + (2*binwidth)) && data[i] < (binlow + (3*binwidth))){
            histogramdata[2]++;
        }
        //bin 4
        else if(data[i] >= (binlow + (3*binwidth)) && data[i] < (binlow + (4*binwidth))){
            histogramdata[3]++;
        }
        //bin 5
        else if(data[i] >= (binlow + (4*binwidth)) && data[i] < (binlow + (5*binwidth))){
            histogramdata[4]++;
        }
        //bin 6
        else if(data[i] >= (binlow + (5*binwidth)) && data[i] < (binlow + (6*binwidth))){
            histogramdata[5]++;
        }
        //bin 7
        else if(data[i] >= (binlow + (6*binwidth)) && data[i] < (binlow + (7*binwidth))){
            histogramdata[6]++;
        }
        //bin 8
        else if(data[i] >= (binlow + (7*binwidth)) && data[i] < (binlow + (8*binwidth))){
            histogramdata[7]++;
        }
        //bin 9
        else if(data[i] >= (binlow + (8*binwidth)) && data[i] < (binlow + (9*binwidth))){
            histogramdata[8]++;
        }
        //bin 10
        else if(data[i] >= (binlow + (9*binwidth)) && data[i] < (binlow + (10*binwidth))){
            histogramdata[9]++;
        }
        //bin 11
        else if(data[i] >= (binlow + (10*binwidth)) && data[i] < (binlow + (11*binwidth))){
            histogramdata[10]++;
        }
        //bin 12
        else if(data[i] >= (binlow + (11*binwidth)) && data[i] < (binlow + (12*binwidth))){
            histogramdata[11]++;
        }
        //bin 13
        else if(data[i] >= (binlow + (12*binwidth)) && data[i] < (binlow + (13*binwidth))){
            histogramdata[12]++;
        }
        //bin 14
        else if(data[i] >= (binlow + (13*binwidth)) && data[i] < (binlow + (14*binwidth))){
            histogramdata[13]++;
        }
        //bin 15
        else if(data[i] >= (binlow + (14*binwidth)) && data[i] < binhigh){
            histogramdata[14]++;
        }
        
    }

    this->histogramvalue = histogramdata;
    
    //how do i even start thinking about this?????

    //this->classhistogram = temphistogram;
}

std::vector<float> ernsts::lab1::gethistogram(){
    //write how to calculate histogram here

    return this->histogramvalue;
}
