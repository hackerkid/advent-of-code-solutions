#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	string x;
	int count;
	int index;
	bool ok;
	int ans;	

	count = 0;
	index = 0;
	ok = true;

	fstream fcin;
	fcin.open("input", ios::in);
	
	while(!fcin.eof() and ok) {
		fcin >> x;
		for (int i = 0; i < x.length(); i++) {
			index++;
			if(x[i] == '(')
				count++;
			else 
				count--;

			if(count == -1) {
				ans = index;
				ok = 0;
				break;
			}
		}
	}

	cout << ans << endl;




}