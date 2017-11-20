#pragma once
#include <string.h>

using namespace std;
class netstat
{
	private:
		int rxPre;
		int txPre;
		int retransPre;
		int rxPost;
		int txPost;
		int retransPost;
		int badSegPre;
		int badSegPost;
		
		int badSegFinal;
		int rxFinal;
		int txFinal;
		int reTransFinal;


	public:
		netstat();
		~netstat();
		
		int getRx(char key);
		int getTx(char key);
		int getReTrans(char key);
		
		void setRx(int value, char key);
		void setTx(int value, char key);
		void setReTrans(int value, char key);

		int getFinalRx();
		int getFinalTx();
		int getFinalReTrans();
		
		void calculateWrite(string fileName);
		void openRead(string nameFile, int indicator);
		int readInValue(string line);

	
};
