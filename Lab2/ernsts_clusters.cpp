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


//write three output files -- one for each of the final clusters
std::ofstream suppressedfile, stationaryfile, expressedfile;

int main(int argc, char* argv[]){

    //what is the point of this??
    float m1, m2;
    ernsts::lab1 lab1(m1, m2);

    // PART 3: read in data file and check that file exists
    FILE* normal_data;
    std::vector<float> normaldata;
    float line;
    float dist1 = 0.0, dist2 = 0.0, dist3 = 0.0;
    float criteria = 1.0;
    float oldmean1 = 0.0, oldmean2 = 0.0, oldmean3 = 0.0;
    float newmean1 = 0.0, newmean2 = 0.0, newmean3 = 0.0;

    if(normal_data = fopen("log_ratio_input.dat", "r")){
        std::cout << "log_ratio_input.dat file exists\n";
    }else{
        std::cout << "log_ratio_input.data cannot be found. it does not exist\n";
        return -1;
    }

    fscanf(normal_data, "%f", &line);

    while(!feof(normal_data)){
        normaldata.push_back(line);
        fscanf(normal_data, "%f", &line);
    }

    //CLUSTER CLASSES/NAMES/MEANS
    k_mean::cluster cluster1;
    k_mean::cluster cluster2;
    k_mean::cluster cluster3;

    //setting cluster names
    cluster1.set_name("expressed");
    cluster2.set_name("suppressed");
    cluster3.set_name("stationary");

    //setting cluster intiial means
    
    // suppressed gene cluster: logratio = -0.5 (initial mean)
    cluster1.set_mean(-0.5);

    // stationary gene cluster: logratio = 0 (initial mean)
    cluster2.set_mean(0.0);

    // expressed gene cluster: logration = 0.5 (initial mean)
    cluster3.set_mean(0.5);

    //while criteria is greater than 0.0001, repeat the following:
    // 1. calculate distance of point to each of three cluster means (define as |a-b|)
    // 2. re-assign data point to closest cluster
    // 3. recalculate cluster means
    // 4. calculate sum of absolute difference of previous & current means
    // criteria = |c1old - c1mean| + |c2old - c2mean| + |c3old - c3mean|

    while(criteria > 0.0001){
        //clear data
        cluster1.clusterdata.clear();
        cluster2.clusterdata.clear();
        cluster3.clusterdata.clear();

        // 1. calculate distance of point to each of three cluster means (define as |a-b|)
        for(int i = 0; i < normaldata.size(); i++){
            //beginning with index i
            dist1 = cluster1.distance(i);
            dist2 = cluster2.distance(i);
            dist3 = cluster3.distance(i);

            // 2. re-assign data point to closest cluster   
            //data point closer to cluster 1
            if(dist1 < dist2 && dist1 < dist3){
                cluster1.clusterdata.push_back(i); 
            }
            //data point closer to cluster 2
            else if(dist2 < dist1 && dist2 < dist3){
                cluster2.clusterdata.push_back(i);
            }
            //data point closer to cluster 3
            else if(dist3 < dist1 && dist3 < dist2){
                cluster3.clusterdata.push_back(i);
            }
        }

        // 3. recalculate cluster means when all points have been reassigned
        oldmean1 = cluster1.get_mean();
        oldmean2 = cluster2.get_mean();
        oldmean3 = cluster3.get_mean();

        //new mean of 1 using stat setters/getters
        lab1.findmean(cluster1.clusterdata);
        newmean1 = lab1.getmean();

        //new mean of 2 using stat setters/getters
        lab1.findmean(cluster2.clusterdata);
        newmean2 = lab1.getmean();
        
        //new mean of 3 using stat setters/getters
        lab1.findmean(cluster3.clusterdata);
        newmean3 = lab1.getmean();

        //setting cluster means for next iteration
        cluster1.set_mean(newmean1);
        cluster2.set_mean(newmean2);
        cluster3.set_mean(newmean3);

        // 4. calculate sum of absolute difference of previous & current means
        // criteria = |c1old - c1mean| + |c2old - c2mean| + |c3old - c3mean|
        criteria = abs(oldmean1 - newmean1) + abs(oldmean2 - newmean2) + abs(oldmean3 - newmean3);

    }

    //output final cluster means to standard output
    std::cout << "cluster 1 final mean: " << cluster1.get_mean() << "\n";
    std::cout << "cluster 2 final mean: " << cluster2.get_mean() << "\n";
    std::cout << "cluster 3 final mean: " << cluster3.get_mean() << "\n";

    char output_buffer[100]; // 100 data points per file
    int j = 0;
    suppressedfile.open("suppresseddata.txt");
    stationaryfile.open("stationarydata.txt");
    expressedfile.open("expresseddata.txt");

    //opening correct file aka list of genes
    if(normal_data = fopen("./microarray/gene_list.txt", "r")){

        while(fgets(output_buffer, sizeof(output_buffer), normal_data) != NULL) {
            //determining first distances
            dist1 = cluster1.distance(normaldata.at(j));
            dist2 = cluster2.distance(normaldata.at(j));
            dist3 = cluster3.distance(normaldata.at(j));

            //data point closer to cluster 1
            if(dist1 < dist2 && dist1 < dist3){
                //print to suppressed
                suppressedfile << output_buffer;
            }
            //data point closer to cluster 2
            else if(dist2 < dist1 && dist2 < dist3){
                stationaryfile << output_buffer;
            }
            //data point closer to cluster 3
            else if(dist3 < dist1 && dist3 < dist2){
                expressedfile << output_buffer;
            }

            j++; //increment to go to next data point
        }
    }

    //close all necessary files
    suppressedfile.close();
    stationaryfile.close();
    expressedfile.close();
    fclose(normal_data);

}