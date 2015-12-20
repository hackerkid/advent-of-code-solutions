#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map <string, int> mp;
int ncount;
int count;
int epicreplace(string x, string y, string z, int start)
{	
	int t;


	string ans;
	if((t = x.find(y, start)) > x.length()) {
		return -1;
	}

	//ans = x.replace(t, z.length(), z);
	ans = x.substr(0, t) + z + x.substr(t+y.length());
	if(mp.count(ans) == 0) {
		mp[ans] = 1;
		count++;
	}
	else {
		ncount++;
	}
	return t;

}
	

int main()
{

	string x;
	string y;
	string z;
	string ans;
	string temp;
	int t;
	fstream fcin;

	fcin.open("day19-input", ios::in);

	fcin >> x;

	t = -1;
	while(!fcin.eof()) {
		fcin >> y;
		fcin >> temp;
		fcin >> z;
		t = -1;
		while((t = epicreplace(x, y, z, t + 1)) != -1) {
		}
	}

	cout << mp.size() << endl;
	cout << ncount << endl;
}	
