#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"

using namespace std;


class fileManip(){
private:
    long int count;
    
public:
    fileManip();

    ~fileManip();

    //opens file and returns nothing
    ifstream* createInputStream(string pathFile);

    void launchScript(string pathScript);

    //search for line and if found write into different file 
    FILE* searchAndWrite(ifstream* fileptr, string keyWord);

    //search file for keyword
    bool searchKey(ifstream* fileptr, string keyWord);

    //read in value from string
    string readInValue(string tobeRead);

    int countOccurence(ifstream* fileptr, string keyWord);
}



