/* 
* date created: 2/7/22
* creator: sarah ernst
* title: lab 1 header file for correlation
* description: creating public functions for correlation between two data sets
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "ernsts_stats.hpp"

#ifndef ernstslab1corr
#define ernstslab1corr

//namespaces can be nested
namespace ernstscorr{

    class lab1corr{
        public:
            //construct new class with an initial name and number of students
            //what is the point of this??
            lab1corr();

            //setter functions
            void findcorrelation(std::vector<float> x, std::vector<float> y);

            //getter functions
            float getcorrelation();

        private:
            //class variables
            float correlationvalue;
    };
}


#endif