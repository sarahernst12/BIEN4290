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
            void sumarray(float array[]); //sums all elements of an array
            void finddiff(float data1[], float data2[], float diffarray[]); //subtracts one array from another element by element
            void finddivide(float ogarr[], float newarray[], float constant); //divides values of array by a constant


            //getter functions
            float getsumarray();

        private:
            //class variables
            float sum;

    };
}

#endif