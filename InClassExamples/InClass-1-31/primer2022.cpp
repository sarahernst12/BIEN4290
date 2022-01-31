#include "primer2022.hpp"

/*
    IF YOU DO THIS -- IT WILL SAY IT WAS NEVER DEFINED
    int get_num_students(){ 
        return num_students;
    }
*/

//follow cascade of indentations for address of things you want to define from hpp
int mySpace::yourSpace::myClass::get_num_students(){ 
    return this->num_students; //you can use keyword this -- everything within these brackets, assumes you're at this address
}