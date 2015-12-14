#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int parser(string x)
{
	int count;
	int n;
	n = x.length() - 1;
	count = 0;
	
	for (int i = 1; i < x.length() - 1; i++) {
		
		if(x.substr(i, 2) == "\\\"") {
			i += 1;
		}

		if(x.substr(i, 2) == "\\x") {
			i += 3;
		}

		if(x.substr(i, 2) == "\\\\") {
			i += 1;
		}

		count++;
		
	}

	return count;

}


int main()
{
	
	fstream fcin;
	string x; 
	int real;
	int vis;
	char a[100];
	real = 0;
	vis = 0;

	fcin.open("input", ios::in);
	
	
	while(!fcin.eof()) {
		fcin >> x;
		real += x.length();
		vis += parser(x);
		
	}

	cout << real - vis << endl;

	

}
