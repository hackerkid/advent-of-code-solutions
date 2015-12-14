#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int parser(string x)
{
	int count;
	int n;
	n = x.length();
	count = 2;

	for (int i = 0; i < n; i++) {
		switch(x[i]) {
			case '\"':
			case '\\':
				count += 2;
				break;
			
			default:
				count++;
				break;
		}
			
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

	cout <<  vis - real << endl;

	

}
