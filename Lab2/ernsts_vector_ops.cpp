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
    this->sum;
}

void genome::lab2::sumarray(std::vector<float> *data) {
    //sum all elements in the array
    int size = (*data).size();
    this->sum = (*data)[0];

    for (int i = 0; i < size; i++){
        this->sum += (*data)[i]; 
    }
}

float genome::lab2::getsumarray(){
    return this->sum;
}

//calculating difference between two arrays
void genome::lab2::finddiff(std::vector<float> *data1, std::vector<float> *data2, std::vector<float> *difference){
    int size1 = (*data1).size();
    
    for(int i = 0; i < size1; i++){
        (*difference)[i] = (*data1)[i] - (*data2)[i];
    }
    
}

//divide array by constant
void genome::lab2::finddivide(std::vector<float> *oggarr, std::vector<float> *newarr, float constant){
    int size = (*oggarr).size();

    for(int i = 0; i < size; i++){
        (*newarr)[i] = ((*oggarr)[i] / constant);
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
