/* 
* date created: 2/1/22
* creator: sarah ernst
* title: lab 1 header file
* description: public functions for statistical analysis
* references: 
*   min/max functions: https://www.techiedelight.com/find-minimum-maximum-value-array-cpp/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#ifndef ernstslab1
#define ernstslab1

//namespaces can be nested
namespace ernsts{

    class lab1{
        public:
            //construct lab1 with an initial name and number of students
            lab1(float, float);

            //setter functions
            void findmin(std::vector<float> data);
            void findmax(std::vector<float> data);
            void findmean(std::vector<float> data);
            void findstandarddev(std::vector<float> data);
            void findhistogram(std::vector<float> data);

            //getter functions
            float getmin();
            float getmax();
            float getmean();
            float getstandarddev();
            std::vector<float> gethistogram();

        private:
            //class variables
            float minimumvalue;
            float maximumvalue;
            float meanvalue;
            float standarddevvalue;
            std::vector<float> histogramvalue{};

    };
}




/*
//calculating maximum of input arrays
float MAX(vector<float> a){
    return *max_element(a.begin(), a.end());
}

//calculating minimum of input arrays
float MIN(float values[]){
    int *min = std::min_element(std::begin(values), std::end(values));

    //std::cout << "The min element is " << *min << std::endl;
    return *min;
}

//calculating standard deviation of input arrays
float STDEV(float values[], int n){
    MEAN(values[], n);
}
*/
#endif