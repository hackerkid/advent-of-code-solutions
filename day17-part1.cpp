#include <iostream>
#include <fstream>
#define tar 150

using namespace std;
int n;
int a[25];

int explore(int i, int sum)
{

	if(i == n) {
		if(sum == tar) {
			return 1;
		}
		else {
			return 0;
		}
	}

	return explore(i+1, sum) + explore(i+1, sum + a[i]);
}

int main()
{

	fstream fcin;
	fcin.open("input", ios::in);
	n = 0;

	while(!fcin.eof()) {
		fcin >> a[n];
		n++;
	}

	cout << explore(0, 0) << endl;

}

