#include <iostream>
#include <fstream>
#define tar 150

using namespace std;
int n;
int a[25];
int mini;

int get_min_no_of_countainers(int i, int sum, int count)
{

	if(i == n) {
		if(sum == tar) {
			mini = min(mini, count);
			return 1;
		}
		else {
			return 0;
		}
	}

	return get_min_no_of_countainers(i+1, sum, count) + get_min_no_of_countainers(i+1, sum + a[i], count + 1);
}

int get_number_of_ways(int i, int sum, int count)
{

	if(i == n) {
		if(sum == tar and count == mini) {
			return 1;
		}
		else {
			return 0;
		}
	}

	return get_number_of_ways(i+1, sum, count) + get_number_of_ways(i+1, sum + a[i], count + 1);
}


int main()
{

	fstream fcin;
	fcin.open("input", ios::in);
	n = 0;
	mini = 88888;

	while(!fcin.eof()) {
		fcin >> a[n];
		n++;
	}

	get_min_no_of_countainers(0, 0, 0);

	cout << mini << endl;
	cout << get_number_of_ways(0, 0, 0) << endl;
}

