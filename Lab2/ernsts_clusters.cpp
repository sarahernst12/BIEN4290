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


int main(int argc, char* argv[]){

    //what is the point of this??
    float m1, m2;
    ernsts::lab1 lab1(m1, m2);
    char output_buffer[100];

    FILE* gene_file;

    //input/output stream for files
    std::ifstream log_ratio_input;
    std::ofstream suppressedfile;
    std::ofstream stationaryfile;
    std::ofstream expressedfile;

    //using arguments
    log_ratio_input.open(argv[1]);
    suppressedfile.open(argv[2]);
    stationaryfile.open(argv[3]);
    expressedfile.open(argv[4]);

    // PART 3: read in data file and check that file exists
    float line;
    float criteria = 1.0;
    float oldmean1 = 0.0, oldmean2 = 0.0, oldmean3 = 0.0;
    float newmean1 = 0.0, newmean2 = 0.0, newmean3 = 0.0;

    if(!log_ratio_input.is_open()){
        std::cout << "log_ratio_input.data cannot be found. it does not exist\n";
        return -1;  
    }
    //std::cout << "log_ratio_input.dat file exists wooo\n";

    //itereate through file from start to end
    std::istream_iterator<float> start_log(log_ratio_input), endg;
    //put start and end of file into vector data
    std::vector<float> log_data(start_log, endg);

    //CLUSTER CLASSES/NAMES/MEANS
    k_mean::cluster cluster1;
    k_mean::cluster cluster2;
    k_mean::cluster cluster3;

    //setting cluster intiial means & names
    
    // suppressed gene cluster: logratio = -0.5 (initial mean)
    cluster1.set_mean(-0.5);
    cluster1.set_name("Suppressed Cluster");

    // stationary gene cluster: logratio = 0 (initial mean)
    cluster2.set_mean(0.0);
    cluster2.set_name("Stationary Cluster");

    // expressed gene cluster: logration = 0.5 (initial mean)
    cluster3.set_mean(0.5);
    cluster3.set_name("Expressed Cluster");

    //std::cout << "the mean of cluster 1 is: " << cluster1.get_mean() << " \n";
    //std::cout << "the mean of cluster 2 is: " << cluster2.get_mean() << " \n";
    //std::cout << "the mean of cluster 3 is: " << cluster3.get_mean() << " \n";

    //while criteria is greater than 0.0001, repeat the following:
    // 1. calculate distance of point to each of three cluster means (define as |a-b|)
    // 2. re-assign data point to closest cluster
    // 3. recalculate cluster means
    // 4. calculate sum of absolute difference of previous & current means
    // criteria = |c1old - c1mean| + |c2old - c2mean| + |c3old - c3mean|
    
    float dist1 = 0.0, dist2 = 0.0, dist3 = 0.0;
    int supcount = 0, statcount = 0, exprescount = 0;

    while(criteria > 0.0001){
        //clear data
        cluster1.clusterdata.clear();
        cluster2.clusterdata.clear();
        cluster3.clusterdata.clear();

        // 1. calculate distance of point to each of three cluster means (define as |a-b|)
        for(int i = 0; i < log_data.size(); i++){
            //beginning with index i
            dist1 = cluster1.distance(log_data.at(i));
            dist2 = cluster2.distance(log_data.at(i));
            dist3 = cluster3.distance(log_data.at(i));

            
            // 2. re-assign data point to closest cluster   
            //data point closer to cluster 1
            if(dist1 < dist2 && dist1 < dist3){
                supcount++;
                cluster1.clusterdata.push_back(log_data.at(i)); 
                //std::cout << "error with cluster 1 point: " << log_data.at(i) << " \n";

            }
            //data point closer to cluster 2
            else if(dist2 < dist1 && dist2 < dist3){
                statcount++;
                cluster2.clusterdata.push_back(log_data.at(i));
                //std::cout << "error with cluster 2 point: " << log_data.at(i) << " \n";

            }
            //data point closer to cluster 3
            else if(dist3 < dist1 && dist3 < dist2){
                exprescount++;
                cluster3.clusterdata.push_back(log_data.at(i));
                //std::cout << "error with cluster 3 point: " << log_data.at(i) << " \n";

            }
            else{
                std::cout << "error with data point: " << log_data.at(i);
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
        //std::cout << "criteria is currently: " << criteria << " \n";
        
    }
    
    //output final cluster means to standard output
    std::cout << "cluster 1 final mean: " << cluster1.get_mean() << "\n";
    std::cout << "cluster 2 final mean: " << cluster2.get_mean() << "\n";
    std::cout << "cluster 3 final mean: " << cluster3.get_mean() << "\n";


   
    //opening correct file aka list of genes
    int j = 0;
    int gene_size = 6118; //default gene size in all files

    if(gene_file = fopen("/lab/bien4290/microarray/gene_list.txt", "r")){
        while(fgets(output_buffer, sizeof(output_buffer), gene_file) != NULL) {
            if(j < gene_size){
                //std::cout << "size of j = " << j << " \n";

                //determining first distances
                dist1 = cluster1.distance(log_data.at(j));
                dist2 = cluster2.distance(log_data.at(j));
                dist3 = cluster3.distance(log_data.at(j));

                //data point closer to cluster 1
                if(dist1 <= dist2 && dist1 < dist3){
                    //print to suppressed
                    suppressedfile << output_buffer;
                }
                //data point closer to cluster 2
                else if(dist2 < dist1 && dist2 < dist3){
                    stationaryfile << output_buffer;
                }
                //data point closer to cluster 3
                else if(dist3 < dist1 && dist3 <= dist2){
                    expressedfile << output_buffer;
                }

                j++; //increment to go to next data point
            }
        }
    }
    
    fclose(gene_file);

    //close all necessary files
    suppressedfile.close();
    stationaryfile.close();
    expressedfile.close();
    log_ratio_input.close();

    return 0;

}