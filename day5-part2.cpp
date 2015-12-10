#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{

	fstream fcin;
	fcin.open("input");
	
	int count;
	int ok;
	string x;
	int ans;
	int a[30][30];
	int k;
	int j;


	ans = 0;
	count = 0;

	while(!fcin.eof()) {
		fcin >> x;
		count++;

		ok = 0;
		memset(a, -1, sizeof a);

		for (int i = 0; i < x.length() - 1; i++) {
			k = x[i] - 'a';
			j = x[i+1] - 'a';
			if(a[k][j] != -1 and a[k][j] != i) {
				ok = 1;
				break;
			}
			else {
				if(a[k][j] != i)
					a[k][j] = i + 1;
			}
		}

		if(!ok)
			continue;

		ok = 0;

		for (int i = 0; i < x.length()-2; i++) {
			if(x[i] == x[i+2]) {
				ok = 1;
				break;
			}
		}

		if(ok) {
			ans++;
		}

	}
	
	cout << ans << endl;	


}




