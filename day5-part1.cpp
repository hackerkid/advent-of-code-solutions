#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int check(char c)
{
	
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;

		default: 
			return 0;
	}

}


int main()
{

	fstream fcin;
	fcin.open("input");
	
	int count;
	int ok;
	char x[200];
	int ans;

	ans = 0;

	while(!fcin.eof()) {
		fcin >> x;
		count = 0;
		ok = 0;

		for (int i = 0; i < strlen(x); i++) {
			if(check(x[i])) {
				count++;
			}

			if(i != 0) {
				if(x[i] == x[i-1]) {
					ok = 1;
				}
			}
		}

		if(count < 3 or ok == 0)
			continue;

		if((strstr(x, "ab") == NULL) and (strstr(x, "cd") == NULL) and (strstr(x, "pq") == NULL) and (strstr(x, "xy") == NULL) )
			ans++;

	}

	cout << ans << endl;

}




