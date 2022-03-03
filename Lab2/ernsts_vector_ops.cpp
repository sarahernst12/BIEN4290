/*
* date created: 2/20/22
* creator: sarah ernst
* title: lab 2 c file
* description: vector ops
* references: 
*/

#include "ernsts_vector_ops.hpp"
#include <iostream> // header in standard library
#include <cmath> // header to include for standarddev function
#include <vector>
#include <string>

//using namespace ernsts;
using namespace genome; 

genome::lab2::lab2(float min, float max){
    //setting all class variables
    min = 0;
    max = 0;
}

float genome::lab2::sumarray(std::vector<float> *data) {
    //sum all elements in the array
    int sum = 0.0;

    int size = (*data).size();

    for (int i = 0; i < size; i++){
        sum += (*data)[i]; 
    }
    return sum;
}

//calculating difference between two arrays
void genome::lab2::finddiff(std::vector<float> *data1, std::vector<float> *data2, std::vector<float> *difference){
    float differencenum = 0;

    int size1 = (*data1).size();
    
    for(int i = 0; i < size1; i++){
        differencenum = ((*data1)[i] - (*data2)[i]);
        difference->push_back(differencenum);
    }
    
}

//divide array by constant
void genome::lab2::finddivide(std::vector<float> *oggarr, std::vector<float> *newarr, float constant){
    float divvalue = 0.0;
    int size = (*oggarr).size();

    for(int i = 0; i < size; i++){
        divvalue = ((*oggarr)[i] / constant);
        newarr->push_back(divvalue);
    }
}

/*
int main(int argc, char* argv[]){
    float min, max;
    float arraysum;
    std::vector<float> hello;
    std::vector<float> hello2;
    std::vector<float> hello3;

    for(int i = 0; i < 100; i++){
        hello[i] = i;
        hello2[i] = i*2;
        //hello3[i] = i - 4;
    }

    genome::lab2 test(min, max);

    //testing sumarray
    test.sumarray(hello);
    arraysum = test.getsumarray();
    std::cout << "sum of array is: " << arraysum << "\n";

    //testing finddiff
    test.finddiff(hello, hello2, hello3);
    
    for(int i = 0; i < hello3.size(); i++){
        std::cout << "difference of index " << i << " is: " << hello3[i] << "\n";
    }

    //testing fiddivide
    test.finddivide(hello, hello3, 5); 
    for(int i = 0; i < hello.size();  i++){
        std::cout << "index " << i << " is: " << hello3[i] << "\n";

    }

}
*/
