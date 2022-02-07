#include "primer2022.hpp"

/*
    IF YOU DO THIS -- IT WILL SAY IT WAS NEVER DEFINED
    int get_num_students(){ 
        return num_students;
    }
*/

//assuming you defined your constructor you need to do this
// the point of a constructor is to construct your object
// it's an initialization process - sometimes it doesn't have any data structures related to it
// constructor is a function named the same thing as a class

mySpace::yourSpace::myClass::myClass(std::string name, int init_num_students){
    //if you want to initialize classname and num students
    //this is where you set class variables up

    this->className = name;
    this->num_students = init_num_students;
}

int mySpace::yourSpace::myClass::get_num_students(){
    return this->num_students;
}

//follow cascade of indentations for address of things you want to define from hpp
int mySpace::yourSpace::myClass::get_num_students(){ 
    return this->num_students; //you can use keyword this -- everything within these brackets, assumes you're at this address
}