/*
*1-31-22 sarah ernst
*This code will act as a primer on class design and creation in C++
*/
#include <iostream>
#include <fstream>
#include <string>

//namespaces allow you to provide context necessary to track different things
//give you address
//mySpace::yourSpace::myClass

namespace mySpace{

    //namespaces can be nested
    namespace yourSpace{

        class myClass{
            public:
                //construct myclass with an initial name and number of students
                myClass(std::string name, int init_num_students); 
                myClass(std::string name);

                int get_num_students();
                std::string get_name();
                void set_num_students(int num);

            private:
                int num_students;
                std::string className;
        };
    }
}