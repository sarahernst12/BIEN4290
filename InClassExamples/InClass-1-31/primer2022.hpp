/*
*1-31-22 sarah ernst
*This code will act as a primer on class design and creation in C++
*/
#include <iostream>
#include <fstream>
#include <string>

class myClass{
    public:
        int get_num_students();
        std::string get_name();
        void set_num_students(int num);

    private:
        int num_students;
        std::string className;
};
