//solutions remain the same as part1. In the input file change the value of a to 3176

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdlib.h>
using namespace std;

struct node
{
	string x;
	string y;
	string w;
	unsigned short oper;
};

unsigned short stoi(string str)
{

	return atoi( str.c_str() );
}

node temp;
map <string, unsigned short> mp;
unsigned short vis[400];
void parser(string x)
{
	
	if(isdigit(x[0])) {
		mp[x] = stoi(x);
	}
}

string tostring(unsigned short x)
{
	
	string res;
	
	while(x) {
		res = (char)(( x % 10) + '0') + res;
		x = x / 10;
	}
	
	return res;
}

int main()
{

	unsigned short t;
	string x;
	string y;
	string oper;
	string stemp;
	string w;
	fstream fcin;
	unsigned short count;
	unsigned short xx;
	unsigned short yy;
	unsigned short marked;
	
	node a[400];
	fcin.open("input", ios::in);
	
	count = 0;

	while(!fcin.eof()) {
		fcin >> x;
		if(x == "NOT") {
			fcin >> x;
			parser(x);
			temp.x = x;
			temp.oper = 0;
			fcin >> stemp;
			fcin >> x;
			parser(x);
			temp.w = x;
			a[count] = temp;
			count++;
			continue;
		}

		parser(x);
		temp.x = x;

		fcin >> oper;
		
		if(oper == "->") {
			temp.oper = 1;
			fcin >> w;
			
			parser(w);

			temp.w = w;
			a[count] = temp;
			count++;
			continue;
		}
		
		
		if(oper == "OR") {
			temp.oper = 2;
		}
		if(oper == "AND") {
			temp.oper = 3;
		}
		
		if(oper == "LSHIFT") {
			temp.oper = 4;
		}
		
		if(oper == "RSHIFT") {
			temp.oper = 5;
		}


		fcin >> y;
		parser(y);
		temp.y = y;
		
		fcin >> stemp;
		fcin >> w;

		parser(w);
		temp.w = w;

		a[count] = temp;
		count++;
	}
	
	marked = 0;
	int round;
	round = 0;

	while(marked < count) {	
		
		for (unsigned short i = 0; i < count; i++) {
			if(vis[i] == 0) {
				switch(a[i].oper) {
					case 0:
						if(mp.count(a[i].x) != 0) {
							xx = mp[a[i].x];
							mp[a[i].w] = ~xx;
							parser(tostring(mp[a[i].w]));
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							marked++;
							vis[i] = 1;
						}
						break;
					case 1:
						if(mp.count(a[i].x) != 0) {
							xx = mp[a[i].x];
							mp[a[i].w] = xx;
							parser(tostring(mp[a[i].w]));
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							marked++;
							vis[i] = 1;
						}
						break;
					case 2:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							mp[a[i].w] = xx | yy;
							parser(tostring(mp[a[i].w]));
							marked++;
							vis[i] = 1;
						}
						break;

					case 3:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							mp[a[i].w] = xx & yy;
							parser(tostring(mp[a[i].w]));
							marked++;
							vis[i] = 1;
						}
						break;

					case 4:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx << yy;
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							parser(tostring(mp[a[i].w]));
							marked++;
							vis[i] = 1;
						}
						break;

					case 5:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx >> yy;
							//cout << "set " << a[i].w <<" via " << a[i].oper <<  endl;
							parser(tostring(mp[a[i].w]));
							marked++;
							vis[i] = 1;
						}
						break;
				}

			}

		}
	}
	
	cout << "a " << mp["a"] << endl;
	
}


