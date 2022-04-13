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
#include <string>

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
    float binlow = 0, binhigh = 0, samplemean = 0;
    float binwidth = 0;
    binwidth = 0.4 * (this->standarddevvalue);
    std::vector<float> histogramdata{}; 

    //std::vector<float>::iterator pRet = histogramdata.end(); //example from linuxhint
    int counter[15];
    for(int i = 0; i < 15; i++){
        counter[i] = 0;
    }

    binlow = this->meanvalue - (3 * this->standarddevvalue);
    binhigh = this->meanvalue + (3 * this->standarddevvalue);

    //populating histogramdata
    // for(int i = 0; i < 14; i++){
    //     histogramdata.insert(i, 0);
    // }
    
    for(int i = 0; i < size; i++){
        
        //bin 1
        if(data[i] >= binlow && data[i] < (binlow+binwidth)){ 
            counter[0]++;
            continue;
        }
        else if(data[i] < binlow){ //anything less than binlow will also be here
            counter[0]++;
            continue;
        }
        //bin 2
        else if(data[i] >= (binlow + binwidth) && data[i] < (binlow + (2*binwidth))){
            counter[1]++;
            continue;
        }
        //bin 3
        else if(data[i] >= (binlow + (2*binwidth)) && data[i] < (binlow + (3*binwidth))){
            counter[2]++;
            continue;
        }
        //bin 4
        else if(data[i] >= (binlow + (3*binwidth)) && data[i] < (binlow + (4*binwidth))){
            counter[3]++;
            continue;
        }
        //bin 5
        else if(data[i] >= (binlow + (4*binwidth)) && data[i] < (binlow + (5*binwidth))){
            counter[4]++;
            continue;
        }
        //bin 6
        else if(data[i] >= (binlow + (5*binwidth)) && data[i] < (binlow + (6*binwidth))){
            counter[5]++;
            continue;
        }
        //bin 7
        else if(data[i] >= (binlow + (6*binwidth)) && data[i] < (binlow + (7*binwidth))){
            counter[6]++;
            continue;
        }
        //bin 8
        else if(data[i] >= (binlow + (7*binwidth)) && data[i] < (binlow + (8*binwidth))){
            counter[7]++;
            continue;
        }
        //bin 9
        else if(data[i] >= (binlow + (8*binwidth)) && data[i] < (binlow + (9*binwidth))){
            counter[8]++;
            continue;
        }
        //bin 10
        else if(data[i] >= (binlow + (9*binwidth)) && data[i] < (binlow + (10*binwidth))){
            counter[9]++;
            continue;
        }
        //bin 11
        else if(data[i] >= (binlow + (10*binwidth)) && data[i] < (binlow + (11*binwidth))){
            counter[10]++;
            continue;
        }
        //bin 12
        else if(data[i] >= (binlow + (11*binwidth)) && data[i] < (binlow + (12*binwidth))){
            counter[11]++;
            continue;

        }
        //bin 13
        else if(data[i] >= (binlow + (12*binwidth)) && data[i] < (binlow + (13*binwidth))){
            counter[12]++;
            continue;
        }
        //bin 14
        else if(data[i] >= (binlow + (13*binwidth)) && data[i] < (binlow + (14*binwidth))){
            counter[13]++;
            continue;
        }
        //bin 15
        else if(data[i] >= (binlow + (14*binwidth)) && data[i] < binhigh){ 
            counter[14]++;
            continue;
        }
        else if(data[i] > binhigh){ //everything above binhigh will be in last bin
            counter[14]++;
            continue;
        }
        else{
            continue;
        }
        
    }

    for (int j = 0; j < 15; j++){
        //starting from beginning of histogramdata vector, adding one, and inputting counter
        //std::vector<float>::iterator pRet = 
        //histogramdata.insert(histogramdata.end(), 1, counter[j]);
        //std::vector<float>::iterator testing= histogramdata.insert(histogramdata.end(), 1, counter[j]);        //needed the itterator portion
        histogramdata.push_back(counter[j]);
    }

    this->histogramvalue = histogramdata;


    //this->histogramvalue = histogramdata;
    
}

std::vector<float> ernsts::lab1::gethistogram(){
    //write how to calculate histogram here

    return this->histogramvalue;
}


     int main(){
         return 0;
     }