/*
* date created: 2/20/22
* creator: sarah ernst
* title: lab 2 header file
* description: public functions for processing data from arrays
* references: 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

//header guards
#ifndef ernstslab2
#define ernstslab2

//namespaces can be nested
namespace genome{

    class lab2{
            //construct lab1 with an initial name and number of students
            lab2(float, float);

            //setter functions
            void sumarray(std::vector<float> data); //sums all elements of an array
            void finddiff(std::vector<float> data1, std::vector<float> data2, std::vector<float> difference); //subtracts one array from another element by element
            void finddivide(std::vector<float> oggarr, std::vector<float> newarr, float constant); //divides values of array by a constant

            //getter functions
            float getsumarray();

        private:
            //class variables
            float sum;

    };
}

#endif