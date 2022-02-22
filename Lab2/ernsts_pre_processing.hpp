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

//header guards
#ifndef ernstslab2pre
#define ernstslab2pre

//namespaces can be nested
namespace genome{

    class preproc{
        public: 
            //construct lab1 with an initial name and number of students
            preproc(float, float);

            //setter functions
            void logratio(std::vector<float> numer, std::vector<float> denom, std::vector<float> logratio);
            

        private:
            //class variables
            

    };
}

#endif