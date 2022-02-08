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

//using namespace ernsts;

ernsts::lab1::lab1(float min, float max){
    //setting all class variables
    this->minimumvalue = 100000;
    this->maximumvalue = -100000;
    this->meanvalue = 0;
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


int main(int argc, char* argv[]){
    float m1, m2;
    ernsts::lab1 test(m1, m2);

    std::vector<float> testarray{1, 2, 3, 4, 5};

    float maximum;
    float minimum; 
    float mean;
    float standarddev;

    //find max
    test.findmax(testarray);
    maximum = test.getmax();
    std::cout << "maximum is: " << maximum << "\n";

    //find min
    test.findmin(testarray);
    minimum = test.getmin();
    std::cout << "minimum is: " << minimum << "\n";

    //find mean
    test.findmean(testarray);
    mean = test.getmean();
    std::cout << "mean is " << mean <<"\n";

    //find standard dev
    test.findstandarddev(testarray);
    standarddev = test.getstandarddev();
    std::cout << "standard deviation is: " << standarddev << "\n";
    

}


/*

float lab1::histogram(std::vector<float> data);{
    //write how to calculate histogram here

    //this->classhistogram = temphistogram;
}
*/