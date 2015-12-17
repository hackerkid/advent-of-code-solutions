#include <iostream>

using namespace std;
int a[30];
int n;

void print()
{
	for (int i = 0;i < n; i++) {
		cout <<(char)(a[i] + 'a');
	}
	cout << endl;
}

int check()
{	int ok;
	ok = 0;

	for (int i = 0; i < n-2; i++) {
		if(((a[i] + 1) == a[i + 1]) and ((a[i+1] + 1) == a[i + 2])) {
			ok = 1;
		}
	}

	if(ok == 0)
		return ok;

	for (int i = 0; i < n; ++i)
	{
		char c;
		c = a[i] + 'a';

		switch(c) {
			case 'i':
			case 'o':
			case 'l':
				return 0;
				break;
		}
	}

	int c;
	ok = 0;

	for (int i = 0; i < n -1; i++) {
		if(a[i] == a[i+1] and ok == 0) {
			c = a[i];
			ok = 1;
			continue;
		}

		if(a[i] == a[i+1] and ok == 1 and c != a[i]) {
			ok = 2;
			break;
		} 

	}

	if(ok == 2) {
		return 1;
	}
	else {
		return 0;
	}
}

void inc()
{	int car;
	car = 1;
	for (int i = n - 1; i >= 0; i--) {
		a[i] = a[i] + car;
		car = a[i] / 26;
		a[i] = a[i] % 26;
	}	
}
int main()
{	
	string x;
	char c;

	x ="cqjxxyzz";
	for (int i = 0; i < x.length(); i++) {
		a[i] = x[i] - 'a';
	}

	n = x.length();
	inc();

	while(!check()) {
		inc();
		//print();
	}
	print();


}