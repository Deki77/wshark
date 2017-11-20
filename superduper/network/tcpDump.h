#pragma once
#include <string.h>
#include <fstream>

using namespace std;
class tcpDump{
	
	private:
		double minTime;
		double maxTime;
		long int numPackets;
	public:
		tcpDump();
		~tcpDump();
		double getMinTime();
		double getMaxTime();
		long int getNumPackets();
		
		void openFile(string nameFile);
		void readTimes(ifstream * ptr);
		double readInValue(string line);

};
