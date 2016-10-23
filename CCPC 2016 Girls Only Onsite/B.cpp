#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int T, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--) {
		cin >> n;
		cout << 1;
		loop(i, n - 1)
			cout << 0;
		cout << endl;
	}
	return 0;
}
