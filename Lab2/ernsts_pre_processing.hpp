/*
* date created: 2/21/22
* creator: sarah ernst
* description: pre processing hpp file
* references: 
*/

#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <math.h>

//header guards
#ifndef ernstslab2pre
#define ernstslab2pre

//namespaces can be nested
namespace genomep{

    class preproc{
        public: 
            //construct lab1 with an initial name and number of students
            preproc(float m1, float m2);

            //setter functions
            void logratio(std::vector<float> numer, std::vector<float> denom, std::vector<float> logratio);    

        private:
            //class variables
            

    };
}

#endif