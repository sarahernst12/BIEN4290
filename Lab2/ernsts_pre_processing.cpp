/*
* date created: 2/21/22
* creator: sarah ernst
* description: pre processing data
*/

#include "ernsts_pre_processing.hpp"
#include "ernsts_k_means.hpp"
#include "ernsts_vector_ops.hpp"
#include "ernsts_stats.hpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>
#include <math.h>

genomep::preproc::preproc(){
    
}

void genomep::preproc::logratio(std::vector<float> *numer, std::vector<float> *denom, std::vector<float> *logratio){
    float logrationum = 0.0;
    int size = (*numer).size();

    for(int i = 0; i < size; i++){
        logrationum = log10((*numer)[i] / (*denom)[i]);
        logratio->push_back(logrationum);
    }
}