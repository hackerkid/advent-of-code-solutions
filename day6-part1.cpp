#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1000

using namespace std;

int a[1000][1000];
int main()
{

	FILE *f;
	char action[10];
	char state[6];
	int x1;
	int x2;
	int y1;
	int y2;
	int count;
	int cs;
	int on;
	int off;
	int toogle;

	on = 0;
	off = 0;
	toogle = 0;

	count = 0;
	f = fopen("input", "r+");
	
	while(fscanf(f, "%s %d,%d through %d,%d", state, &x1, &y1, &x2, &y2) != -1) {
		cout << state << endl;
		
		if(!strcmp(state,"on"))
			cs = 1;
		else 
			if(!strcmp(state,"off"))
				cs = 2;
			else 
				cs = 3;

		
		switch(cs) {
			case 1:
				on++;
				for (int i = x1; i <= x2; i++) {
					for (int j = y1; j <= y2; j++) {
						a[i][j] = 1;
					}
				}
				break;
			
			case 2:
				off++;
				for (int i = x1; i <= x2; i++) {
					for (int j = y1; j <= y2; j++) {
						a[i][j] = 0;
					}
				}
				break;
			
			case 3:
				toogle++;
				for (int i = x1; i <= x2; i++) {
					for (int j = y1; j <= y2; j++) {
						a[i][j] = (a[i][j] + 1) % 2;
					}
				}
				break;

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			count += a[i][j];
		}
	}
	
	cout << count << endl;
}

