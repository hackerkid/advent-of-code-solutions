#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map <string, int> mp;

bool check(string x, int x1)
{
	return mp[x] == x1;
	
}

int main()
{

	//remove : and , before reading input (ctrl + h would do the job)
	fstream fcin("input");
	
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

	while(fcin >> sue >> no >> x >> x1 >> y >> y1 >> z >> z1) {
		
		if(check(x, x1) && check(y, y1) && check(z, z1)) {
			cout << no << "\n";
		}

	}

}

