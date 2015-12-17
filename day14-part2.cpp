#include <iostream>
#include <fstream>
#define FLY 5555
#define SLEEP 6666

int tar;
int ft[12];
int fd[12];
int sleep[12];
int n;
int points[12];


using namespace std;

int explore(int i, int remain, int mode)
{	
	int flytime = ft[i];
	int flydist = fd[i];
	int wait = sleep[i];

	if(mode == FLY) {
		if(remain >= flytime) {
			return flytime * flydist + explore(i, remain - flytime, SLEEP);
		}
		else {
			return remain * flydist;
		}
	}

	if(mode == SLEEP) {
		if(remain >= wait) {
			return explore(i, remain - wait, FLY);
		}
		else {
			return 0;
		}
	}
}
int main()
{

	int maxi;
	maxi = -1;

	fstream fcin;
	fcin.open("day14-input", ios::in);
	n = 0;

	fcin >> tar;
	while(!fcin.eof()) {
		fcin >> fd[n];
		fcin >> ft[n];
		fcin >> sleep[n];
		n++;
	}


	for (int i = 1; i <= tar; i++) {
		maxi = -1;
		for (int j = 0; j < n; j++) {
			maxi = max(maxi, explore(j, i, FLY));
		}

		for (int j = 0; j < n; j++) {
			if(explore(j, i, FLY) == maxi) {
				points[j]++;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << points[i] << endl;
	}

	
}