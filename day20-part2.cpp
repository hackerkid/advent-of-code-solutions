#include <iostream>
#define N 1000000
using namespace std;

long long a[N];
int main()
{
	long long maxi;
	maxi = -1;

	for (int i = 1; i < N; i++) {
		for (int j = i, k = 0; j < N and k < 50; j += i, k++) {
			a[j] += (i * 11);
		}
	}

	for (int i = 1; i < N; i++) {
		if(a[i] >= 34000000) {
			cout << i << endl;
			break;
		}
	}




}

	
