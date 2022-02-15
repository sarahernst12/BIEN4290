/* 
* date created: 2/15/22
* creator: sarah ernst
* title: cpp file for mini project 0
* objective of mini project: part 1: to hack time
*/

#include "ernsts_MiniProject0.hpp"
#include <unistd.h>
#include <iostream>

WhatTheHack::TimeHacking::TimeHacking(std::string objectToHack){
    //setting all class variables
    this->time_to_hack;
    this->objectToHack;
}

//setter: setting time to hack from user input
void WhatTheHack::TimeHacking::setTimeToHack(int seconds){
    this->time_to_hack = seconds;
}


//getter: returning time to hack
int WhatTheHack::TimeHacking::getTimeToHack(){
    return this->time_to_hack;
}

//setter: setting object to hack
void WhatTheHack::TimeHacking::setObjectToHack(std::string object){
    this->objectToHack = object;
}

//getter: returning object to hack
std::string WhatTheHack::TimeHacking::getObjectToHack(){
    return this->objectToHack;
}

//hackTime should sleep for the number of seconds 
//the user indicated before indicating that time was hacked
void WhatTheHack::TimeHacking::hackTime(){
    sleep(this->time_to_hack);
}

//main file
int main(int argc, char* argv[]){
    std::string temporaryObject;
    int temporaryTime;

    //creating instance of class
    WhatTheHack::TimeHacking itsTime(temporaryObject); 

    //asking user which object they want to hack
    std::cout <<"Which object would you like to hack?\n";
    std::cin >> temporaryObject;

    //asking user how many seconds they would like to hack
    std::cout <<"\nFor how long would you like to hack?\n";
    std::cin >> temporaryTime;

    //setting and returning time stated and object to hack
    itsTime.setTimeToHack(temporaryTime);
    temporaryTime = itsTime.getTimeToHack();
    itsTime.setObjectToHack(temporaryObject);
    temporaryObject = itsTime.getObjectToHack();

    //returning responses to user
    std::cout << "\nHere's the time you stated: " << temporaryTime;

    std::cout << "\nHacking is in progress.\n";

    itsTime.hackTime();

    std::cout<< "\n" << temporaryObject << " has been hacked for " << temporaryTime << " seconds!!\n\n";
    

}


