/* 
* date created: 2/7/22
* creator: sarah ernst
* title: lab 1 correlation cpp file 
* description: math to calculate correlation coefficient between two data sets
* references: 
*/

#include "ernsts_stats.hpp"
#include "ernsts_corr.h"
#include "ernsts_stats.cpp"
#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>

//using namespace ernsts;
ernstscorr::lab1corr::lab1corr(){
    //setting all class variables
    this->correlationvalue;
}

/* //included ernsts_stats.cpp file instead
ernsts::lab1::lab1(float min, float max){
    this->minimumvalue;
    this->maximumvalue;
    this->meanvalue;
    this->standarddevvalue;
    std::vector<float> histogramvalue{};
}
*/

void ernstscorr::lab1corr::findcorrelation(std::vector<float> x, std::vector<float> y) {
    float m1, m2;
    ernsts::lab1 test(m1, m2); //set up constructor for lab1 class

    //how to calculate minimum element of vector
    int x_size = x.size();
    //int y_size = y.size();

    float sumnum, num, meanx, meany;
    float denomleft, denomright, denom, correlation;

    //find mean of x
    test.findmean(x);
    meanx = test.getmean();
    //std::cout << "mean of x is " << meanx <<"\n";

    //find mean of y
    test.findmean(y);
    meany = test.getmean();
    //std::cout << "mean of y is " << meany <<"\n";

    for (int i = 0; i < x_size; i++){ //x and y have the same size so doesn't matter if x_size or y_size
        sumnum += (x[i] * y[i]); //sigma (xi)(yi)
        denomleft += pow(x[i], 2); //sigma(xi squared) - N(x mean squared)
        denomright += pow(y[i], 2); //sigma(yi squared) - N(y mean squared) 
    }
    
    //calculating numerator
    num = sumnum - (x_size)*(meanx)*(meany);

    //calculating denominator
    denomleft = denomleft - (x_size)*pow(meanx, 2);
    denomright = denomright - (x_size)*pow(meany, 2);
    
    //denom
    denom = (denomleft)*(denomright);
    denom = sqrt(denom);

    correlation = num / denom;

    this->correlationvalue = correlation;
}


float ernstscorr::lab1corr::getcorrelation(){
    //return correlation value here
    return this->correlationvalue;
}
/*
int main(int argc, char* argv[]){
    return 0;
}
*/
