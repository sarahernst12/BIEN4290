/*
* date created: 2/24/22
* creator: sarah ernst
* description: k-means & clustering
*/

#include "ernsts_k_means.hpp"
#include "ernsts_pre_processing.hpp"
#include "ernsts_vector_ops.hpp"
#include "ernsts_stats.hpp"
#include <iostream> // header in standard library
#include <iterator>
#include <fstream>
#include <sstream>
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>

//initializing class variables
k_mean::cluster::cluster() {
    this->objectmean = 0.0;
    this->objectname = "";
    this->clusterdata;
}



float k_mean::cluster::distance(float data) {
    // initialize variables
    float distance = 0.0;
    float mean = this->objectmean;
    
    // calculate the one dimensional distance of the data point to the cluster mean
    distance = abs(data - mean);

    return distance;
}

void k_mean::cluster::set_name(std::string name) {
    this->objectname = name;
}

void k_mean::cluster::set_mean(float mean) {
    this->objectmean = mean;
}

std::string k_mean::cluster::get_name() {
    return this->objectname;
}

float k_mean::cluster::get_mean() {
    return this->objectmean;
}

