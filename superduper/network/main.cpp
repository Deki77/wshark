#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
//#include "netstat.h"
#include "tcpDump.h"

using namespace std;

int main(){
	system("./tcpdump.tcl");
	//netstat * netPtr = new netstat();
	tcpDump * tcpPtr = new tcpDump();
	string aLine = "";
	//string aLine2 = "";
	tcpPtr->openFile("tcpdump.txt");
	//netPtr->openRead("files/file1.txt",1);
	//netPtr->openRead("files/file2.txt",2);
	//netPtr->calculateWrite("files/file3.txt");
	/*
	ifstream fileFinal("files/file3.txt");
	
	if(fileFinal.is_open()){
		while(getline(fileFinal,aLine))
			cout << aLine << endl;			
	}
	
	fileFinal.close();
	*/
	double finalValue = 0.0;
	finalValue = (1448*8*tcpPtr->getNumPackets())/(tcpPtr->getMaxTime()-tcpPtr->getMinTime());
	cout << "Num Packets: " << tcpPtr->getNumPackets() << " Max Time: " << tcpPtr->getMaxTime() << " Min Time: " << tcpPtr->getMinTime() << endl;
	cout << "Transfer rate: " << finalValue/1000000 << " Mbps" << endl;

	return 0;
}
