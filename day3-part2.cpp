#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <fstream>
using namespace std;

int main()
{

	fstream fcin;
	string inp;
	pair <int, int> pos;
	map < pair <int, int>, bool> mp;
	int ans;

	fcin.open("input", ios::in);
	fcin >> inp;
	
	
	pos.first = 0;
	pos.second = 0;
	mp[pos] = true;
	ans = 1;

	for (int i = 0; i < inp.length(); i += 2) {
		switch(inp[i]) {
			case '^':
				pos.first--;
				break;
			case 'v':
				pos.first++;
				break;
			case '>':
				pos.second++;
				break;
			case '<':
				pos.second--;
				break;
		}

		if(mp.count(pos) == 0) {
			ans++;
			mp[pos] = true;
		}

	}

	pos.first = 0;
	pos.second = 0;
	
	for (int i = 1; i < inp.length(); i += 2) {
		switch(inp[i]) {
			case '^':
				pos.first--;
				break;
			case 'v':
				pos.first++;
				break;
			case '>':
				pos.second++;
				break;
			case '<':
				pos.second--;
				break;
		}

		if(mp.count(pos) == 0) {
			ans++;
			mp[pos] = true;
		}

	}

	cout << ans << endl;

}

