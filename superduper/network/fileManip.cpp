#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "string.h"

using namespace std;

fileManip::fileManip(){
    count = 0;
};

fileManip::~fileManip(){
};

//opens file, creates input stream and then returns pointer to that stream
void fileManip::createInputStream(string pathFile){
    ifstream myFile(nameFile.c_str());
    ifstream * fileptr = &myFile;
    return fileptr;
};

void fileManip::launchScript(string pathScript){
    system(pathScript);
};


//search for line and if found write into different file 
FILE* fileManip::searchAndWrite(ifstream* fileptr, string outFile, string keyWord){
    ofstream writeFile;
    writeFile.open("outFile");
    string line = "";
    if(writeFile.isOpen()){
        while(getline(*fileptr, line)){
                if(searchLine(line, keyWord))
                    writeFile << line << endl;
                 else
                    //do nothing
        }
    }
    writeFile.close();
    return &writeFile;
};

//search file for keyword
bool fileManip::searchLine(string line, string keyWord){
    bool valueRet = false;
    int ind = line.find(keyWord);
    if(ind!=-1)
        valueRet = true;     
    }
    return valueRet;

};

//read in first value from string
string fileManip::readFirstValueOnLine(string tobeRead){
    string value = "";
	stringstream ss(tobeRead);
	ss >> value;
	return value;
};

string fileManip

int fileManip::countOccurence(ifstream* fileptr, string keyWord);