#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, a, b;
	cin >> T;
	while(T--) {
		cin >> a >> b;
		cout << a + b + max(a, b) << endl;
	}
	return 0;
}
