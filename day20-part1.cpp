#include <iostream>
#define N 1000000
using namespace std;

long long a[N];
int main()
{
	long long maxi;
	maxi = -1;

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			a[j] += i;
		}
	}

	for (int i = 1; i < N; i++) {
		if(a[i] >= 3400000) {
			cout << i << endl;
			break;
		}
	}




}

	
