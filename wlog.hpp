// basic file operations
#include <iostream>
#include <fstream>
using namespace std;


namespace my{
    bool in_file(std::string);
    
    bool in_file(std::string text) {
        ofstream myfile;
        myfile.open ("log.txt",ios::out | ios::app);
        if(myfile.is_open()) {
            myfile << text + "\n";
            if(myfile.fail()) {
                return false;
            } 
            myfile.close();
        } else{
            return false;
        }
        return true;
    }
    
}
