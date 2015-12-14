#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
using namespace std;

map <string, int> mp;
int a[30][30];

int check(int vis[])
{
	for (int i = 1; i <= mp.size(); i++)
		if(vis[i] == 0)
			return 0;

	return 1;
}

int explore(int i, int vis[])
{	
	int dis;
	int mini = -1000000;

	vis[i] = 1;

	if(check(vis)) {
		vis[i] = 0;
		return 0;
	}

	for (int j = 1; j <= mp.size(); j++) {
		if(i == 0 or (vis[j] == 0 and a[i][j]))
			mini = max(mini, a[i][j] + explore(j, vis));
	}

	vis[i] = 0;

	return mini;
}
int main()
{

	fstream fcin;
	string x;
	string y;
	string temp;
	int w;
	int vis[12];


	fcin.open("input", ios::in);
	memset(vis, 0, sizeof vis);

	while(!fcin.eof()) {
		fcin >> x;
		fcin >> temp;
		fcin >> y;
		fcin >> temp;
		fcin >> w;
		
		if(mp.count(x) == 0) {
			mp[x] = mp.size();
		}

		if(mp.count(y) == 0) {
			mp[y] = mp.size();
		}

		a[mp[x]][mp[y]] = w;
		a[mp[y]][mp[x]] = w;

		//cout << mp[x] << " " << mp[y] << " " << w << endl;


	}


	cout << explore(0, vis) << endl;
}