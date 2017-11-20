#include "tcpDump.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

tcpDump::tcpDump(){
	minTime = 0.0;
	maxTime = 0.0;
	numPackets = 0;
}

tcpDump::~tcpDump(){

}

double tcpDump::getMinTime(){
	return minTime;
}

double tcpDump::getMaxTime(){
	return maxTime;
}

long int tcpDump::getNumPackets(){
	return numPackets;
}

void tcpDump::openFile(string nameFile){
	ifstream myFile(nameFile.c_str());
	ifstream * fileptr = &myFile;
	if(myFile.is_open())
		readTimes(fileptr);
	myFile.close();
}

void tcpDump::readTimes(ifstream * ptr){
	string aLine = "";
	double temp = 0.0;
	while(getline(*ptr, aLine)){
		temp = readInValue(aLine);	
		if(minTime == 0)
			minTime = temp;
		else if(temp < minTime)
			minTime = temp;
		else if(temp > maxTime)
			maxTime = temp;
		numPackets++;
	}
}

double tcpDump::readInValue(string line){
	double value = 0.0;
	stringstream ss(line);
	ss >> value;
	return value;
}
