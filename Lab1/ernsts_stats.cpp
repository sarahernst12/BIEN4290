/* 
* date created: 2/1/22
* creator: sarah ernst
* title: lab 1 stats cpp main file
* description: main function to call functions from hpp
* references: 
*/

#include "ernsts_stats.hpp"
#include <iostream> // header in standard library

//using namespace ernsts;

ernsts::lab1::lab1(float min, float max){
    //setting all class variables to 0
    this->minimumvalue = 100000;
    this->maximumvalue = -100000;

}

void ernsts::lab1::findmin(std::vector<float> data) {
    //how to calculate minimum element of vector
    int size = data.size();

    float minimum;
    minimum = data[0];
    for (int i = 0; i < size; i++){
        if (data[i] < minimum){
            this->minimumvalue = data[i];
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
        }
    }
}

float ernsts::lab1::getmax(){
    return this->maximumvalue;
}

int main(int argc, char* argv[]){
    float m1, m2;
    ernsts::lab1 test(m1, m2);

    std::vector<float> testarray{1, 2, 3, 4, 5};

    float maximum;

    test.findmax(testarray);
    maximum = test.getmax();

    std::cout << "maximum is: " << maximum << "\n";
}


/*
float lab1::mean(std::vector<float> data) {
    //write how to calculate mean here

    //this->classmean = teampmean;
}

float lab1::standarddev(std::vector<float> data) {
    //write how to calculate standarddev here

    //this->classstandarddev = tempstandarddev;
}

float lab1::histogram(std::vector<float> data);{
    //write how to calculate histogram here

    //this->classhistogram = temphistogram;
}
*/