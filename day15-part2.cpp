#include <iostream>
#include <fstream>
using namespace std;

int a[10][4];
int n;

long long score(int x, int y, int z)
{
	long long ans;
	long long sum;
	int v[4];
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 100 - (x + y + z);

	//cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	ans = 1;

	for (int i = 0; i < 5; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[j][i] * v[j];
		}

		if(sum < 0) {
			ans = 0;
		}
		
		if(i != 4)
			ans = ans * sum;

	}
	
	long long cal;
	cal = 5 * v[0] + 8 * v[1] + 6 * v[2] + 1 * v[3];
	if(cal != 500)
		return 0;

	
	return ans;
}
int main()
{

	fstream fcin;
	//check the input
	fcin.open("day15-input", ios::in);
	long long maxi;

	maxi = -1;

	n = 0;

	while(!fcin.eof()) {
		for (int i = 0; i < 5; i++) {
			fcin >> a[n][i];
		}
		n++;
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100 - i; j++) {
			for (int k = 0; k <= 100 - (i + j) ; k++) {
				maxi = max(score(i, j, k), maxi);
			}
		}
	}


	cout << maxi << endl;


}