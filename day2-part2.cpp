#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{

	int x;
	int y;
	int z;
	int a[3];
	long long area;
	FILE *fp = fopen("input", "r+");

	area = 0;
	int count;
	count = 0;
	while(fscanf(fp, "%dx%dx%d", a, a + 1,a + 2) != -1) {
		sort(a, a +3);
 		area += 2 * (a[0]  + a[1] ) + a[0] * a[1] * a[2];
 	}
 	cout << area << endl;

 }

