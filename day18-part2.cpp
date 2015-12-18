#include <iostream>
using namespace std;

int a[1100][1100];
int temp[1100][1100];
int N;
int check(int i, int j)
{

	int count;
	count = 0;
	int ch1[] = {1, -1, 0, 1, -1, 0, 1, -1};
	int ch2[] = {1, 1, 1, -1, -1, -1, 0, 0};

	for (int k = 0; k < 8; k++) {
		int x = i + ch1[k];
		int y = j + ch2[k];
		if((x >= 0 and x < N) and (y >= 0 and y < N) and a[x][y]) {
			count++;
		}
	}

	if(a[i][j]) {
		if((count == 2 or count == 3)) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if(!a[i][j]) {
		if(count == 3) {
			return 1;
		}
		else {
			return 0;
		}
	}

}

int get_count()
{
	int count;
	count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(a[i][j])
				count++;
		}
	}

	return count;

}
void copytemp2a()
{

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = temp[i][j];
		}
	}

}


void copya2temp()
{

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = a[i][j];
		}
	}

}

int checkcorner(int x, int y)
{
	if(x == 0 and y == N-1)
		return true;

	if(x == 0 and y == 0)
		return true;

	if(x == N-1 and y == 0)
		return true;

	if(x == N-1 and y == N-1)
		return true;

	return false;
}
int main()
{
	char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			if(c == '#') {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	

	// DONT MISS THIS STEP
	a[N-1][0] = 1;
	
	

	for (int cs = 1; cs <= 100; cs++) {
		copya2temp();
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(checkcorner(i, j	)) {
					//cout << i << " " << j << endl;
					continue;
				}
				temp[i][j] = check(i, j);
			}
		}
		
		copytemp2a();
		

	}
	
	cout << " " <<  get_count() << endl;

}



