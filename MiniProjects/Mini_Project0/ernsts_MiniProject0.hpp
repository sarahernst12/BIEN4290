/* 
* date created: 2/15/22
* creator: sarah ernst
* title: mini project 0 header for how to hack time
* objective of mini project: hack time
* description: getting good practice using c++ and establishing good coding practices
*/

//adding libraries
#include <iostream>
#include <unistd.h>

//creating header guards
#ifndef minime1
#define minime1

//namespace of my Choice
namespace WhatTheHack{
    //class name TimeHacking
    class TimeHacking{
        //public members
        public:
            //constructor
            TimeHacking(std::string objectToHack);

            //functions
            void setTimeToHack(int seconds);
            int getTimeToHack();
            void setObjectToHack(std::string object);
            std::string getObjectToHack();
            void hackTime();

        //private members
        private:
            int time_to_hack;
            std::string objectToHack;

    };
}

#endif

