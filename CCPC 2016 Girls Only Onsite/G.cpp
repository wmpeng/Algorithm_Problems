#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int T, q, k;

bool solve(int n, int m)
{
	if (n > m)
		swap(n, m); // n <= m
	if (n % k == 0)
		return true;

	int len = n / k;
	if (k > 2 && (len & 1))
		return (n + m) % 2 == 0;
	else
		return (n + m) % 2 != 0;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	int m, n;
	while(T--) {
		cin >> q >> k;
		++k;
		while (q--) {
			cin >> n >> m;
			cout << (solve(n, m) ? "Alice": "Bob") << endl;
		}
	}
	return 0;
}
