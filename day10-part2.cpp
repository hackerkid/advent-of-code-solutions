//huge performance improvement when + was replaced with append

#include <iostream>

using namespace std;

string x;
string res;

string tostring(long long x)
{
	string res;

	while(x)
	{
		res = (char) (x % 10 + '0') + res;
		x = x / 10; 
	}

	return res;
}

int main()
{

	long long n;
	long long t;
	long long count;
	int last;
	last = 0;
	x = "1321131112";
	
	t = 50;

	for (long long cs = 1; cs <= t; cs++) {
		n = x.length();
		res = "";
		for (long long i = 0; i < n; i++) {
			count = 1;
			while((i + 1 < n) and (x[i] == x[i+1])) {
				count++;
				i++;
			}
			res = res.append(tostring(count));
			res = res.append(tostring(x[i] - '0'));
		}

		x = res;
		last = x.length();
	}

	cout << x.length() << endl;

}