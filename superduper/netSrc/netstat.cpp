#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include "netstat.h"

using namespace std;

netstat::netstat(){

	rxPre = 0;
	txPre = 0;
	retransPre = 0;
	rxPost = 0;
	txPost = 0;
	retransPost = 0;

	rxFinal = 0;
	txFinal = 0;
	reTransFinal = 0;
}

netstat::~netstat(){
}

int netstat::getRx(char key){
	int temp = 0;
	
	if(key == 'b')
		temp = rxPre;
	else
		temp = rxPost;
	
	return temp;
}

int netstat::getTx(char key){
	int temp = 0;
	
	if(key == 'b')
		temp = txPre;
	else
		temp = txPost;
	
	return temp;
}

int netstat::getReTrans(char key){
	int temp = 0;
	
	if(key == 'b')
		temp = retransPre;
	else
		temp = retransPost;
	
	return temp;
}

int netstat::getFinalRx(){
	return rxFinal;
}

int netstat::getFinalTx(){
	return txFinal;
}

int netstat::getFinalReTrans(){
	return reTransFinal;
}

void netstat::setRx(int value, char key){
	if(key == 'b')
		rxPre = value;
	else
		rxPost = value;
}

void netstat::setTx(int value, char key){
	if(key== 'b')
		txPre = value;
	else
		txPost = value;
}

void netstat::setReTrans(int value, char key){
	if(key == 'b')
		retransPre = value;
	else 
		retransPost = value;
}

void netstat::openRead(string nameFile, int indicator){
	//Indicator 1 is for before copying over file, 2 is after copying over file.
	string temp  = "";
	temp = nameFile;
	ifstream myFile(temp.c_str());
	string aLine = "";
	size_t foundRec;
	size_t foundSent;
	size_t reTransmit;
	size_t badSegs;	
	if(myFile.is_open()){

		while(getline(myFile, aLine)){
			foundRec = aLine.find("segments received");
			foundSent = aLine.find("segments send out");		
			reTransmit = aLine.find("segments retransmited");
			badSegs = aLine.find("bad segments received");
			
			if(foundRec != -1){
				if((indicator == 1) && (rxPre == 0))
					rxPre = readInValue(aLine);
				else if((indicator == 2) && (rxPost == 0))
					rxPost = readInValue(aLine);
			}
			else if(foundSent !=  -1){
				if(indicator == 1)
					txPre = readInValue(aLine);
				else
					txPost = readInValue(aLine);	
			}
			else if(reTransmit != -1){
				if(indicator == 1)
					retransPre = readInValue(aLine);
				else
					retransPost = readInValue(aLine);	
			}
			else if(badSegs != -1){
				if(indicator == 1)
					badSegPre = readInValue(aLine);
				else
					badSegPost = readInValue(aLine);
			}									
				
		}	
	}
	myFile.close();
}

int netstat::readInValue(string line){
	int value = 0;
	stringstream ss(line);
	ss >> value;
	return value;
}


void netstat::calculateWrite(string fileName){
	rxFinal = rxPost - rxPre;
	txFinal = txPost - txPre;
	reTransFinal = retransPost - retransPre;
	badSegFinal = badSegPre - badSegPost;

	//ofstream writeFile(fileName.c_str());
	fstream writeFile;
	writeFile.open(fileName.c_str(), fstream::out | fstream::app);
	if(writeFile.is_open()){
		writeFile << "Total number of receieved segments is: " << rxFinal << endl;
		writeFile << "Total number of sent segments is: " << txFinal << endl;
		writeFile << "Total number of dropped packets is: " << reTransFinal << endl;
		writeFile << "Total number of bad segments is: " << badSegFinal << endl;		
	}

	writeFile.close();
}

