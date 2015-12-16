#include <iostream>
#include <fstream>
#include <map>
#include <limits.h>

int a[12][12];
int n;
int vis[12];
int count;
using namespace std;

bool ok()
{
	for (int i = 1; i <= n; i++) {
		if(!vis[i])
			return false;
	}
	return true;
}

int explore(int i, int k)
{
	int maxi;
	maxi = INT_MIN;

	if(ok()) {
		return a[i][k] + a[k][i];
	}

	for (int j = 1; j <= n; j++ ) {
		if(vis[j] == 0) {
			vis[j] = 1;
			maxi = max(explore(j, k) + a[i][j] + a[j][i], maxi);
			vis[j] = 0;
		}
	}

	return maxi;
}

int main()
{
	fstream fcin;
	//check the input format
	fcin.open("day15-input", ios::in);
	string x;
	string y;
	int xx;
	int yy;
	int w;
	string act;
	map <string, int> mp;
	mp["you"] = 1;
	while(!fcin.eof()) {
		fcin >> x;
		fcin >> act;
		fcin >> w;
		fcin >> y;
		
		if(mp.count(x) == 0) {
			xx = mp[x] = mp.size();
		}
		else {
			xx = mp[x];
		}

		if(mp.count(y) == 0) {
			yy = mp[y] = mp.size();
		}
		else {
			yy = mp[y];
		}

		if(act == "lose") {
			w = -w;
		}

		a[xx][yy] = w;
	}
	
	n =  mp.size();
	int maxi;
	maxi = INT_MIN;

	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		maxi = max(explore(i, i), maxi);
		vis[i] = 0;
	}

	cout << maxi << endl;

}