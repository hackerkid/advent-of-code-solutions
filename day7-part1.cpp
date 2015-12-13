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
	int oper;
};

int stoi(string str)
{

	return atoi( str.c_str() );
}

node temp;
map <string, int> mp;
int vis[400];
void parser(string x)
{
	
	if(isdigit(x[0])) {
		mp[x] = stoi(x);
	}
}
int main()
{

	int t;
	
	string x;
	string y;
	string oper;
	string stemp;
	string w;
	fstream fcin;
	int count;
	int xx;
	int yy;
	int marked;
	
	node a[400];
	fcin.open("input", ios::in);
	
	count = 0;

	while(!fcin.eof()) {
		fcin >> x;
		if(x == "NOT") {
			fcin >> x;
			parser(x);
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
	while(marked < count) {	
		for (int i = 0; i < count; i++) {
			if(vis[i] == 0) {
				switch(a[i].oper) {
					case 0:
						if(mp.count(a[i].x) != 0) {
							xx = mp[a[i].x];
							mp[a[i].w] = ~xx;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;
					case 1:
						if(mp.count(a[i].x) != 0) {
							xx = mp[a[i].x];
							mp[a[i].w] = xx;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;
					case 2:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx | yy;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;

					case 3:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx & yy;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;

					case 4:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx << yy;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;

					case 5:
						if(mp.count(a[i].x) != 0 and mp.count(a[i].y) != 0) {
							xx = mp[a[i].x];
							yy = mp[a[i].y];
							mp[a[i].w] = xx >> yy;
							cout << "set " << a[i].w << endl;
							marked++;
							vis[i] = 1;
						}
						break;
				}

			}

		}
	}
	
	cout << mp["d"] << endl;
	cout << mp["e"] << endl;
	cout << mp["f"] << endl;
	cout << mp["g"] << endl;
	cout << mp["h"] << endl;
	cout << mp["i"] << endl;
	cout << mp["x"] << endl;
	cout << mp["y"] << endl;
	
	for (int i = 0; i < count; i++) {
		//cout << a[i].x << " " << a[i].y << " " << a[i].w << endl;
	}
}


