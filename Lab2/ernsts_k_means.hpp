/*
* date created: 2/24/22
* creator: sarah ernst
* description: k-means hpp file for clustering
* references: 
*/

#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "ernsts_stats.hpp"

//header guards
#ifndef ernstslab2kmean
#define ernstslab2kmean

namespace k_mean {
    class cluster {
        public:
            cluster(); //class constructor

            float distance(float data);
            std::vector<float> clusterdata;

            //setters
            void set_name(std::string name);
            void set_mean(float mean);

            //getters
            std::string get_name();
            float get_mean();
        
        private: //global class variables
            std::string objectname;
            float objectmean;
    };
}


#endif