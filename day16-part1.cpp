#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map <string, int> mp;

bool check(string x, int x1)
{
	if(mp[x] == x1) {
		return true;
	}

	return false;
}


int main()
{

	fstream fcin;
	//remove : and , before reading input (ctrl + h would do the job)
	fcin.open("input", ios::in);
	
	mp["children"] =  3;
	mp["cats"] =  7;
	mp["samoyeds"] =  2;
	mp["pomeranians"] =  3;
	mp["akitas"] =  0;
	mp["vizslas"] =  0;
	mp["goldfish"] =  5;
	mp["trees"] =  3;
	mp["perfumes"] =  1;
	mp["cars"] =  2;

	string sue;
	string x;
	string y;
	string z;
	int x1;
	int y1;
	int z1;	
	int no;

	while(!fcin.eof()) {
		fcin >> sue;
		fcin >> no;
		fcin >> x;
		fcin >> x1;
		fcin >> y;
		fcin >> y1;
		fcin >> z;
		fcin >> z1;
		
		if(check(x, x1) and check(y, y1) and check(z, z1)) {
			cout << no << endl;
		}

	}

}

