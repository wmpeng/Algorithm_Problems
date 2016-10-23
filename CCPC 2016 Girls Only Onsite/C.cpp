#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int T, n, sum, t;
map<int, int> cnt;

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		sum = 0;
		cnt.clear();
		loop(i, n - 1) {
			cin >> t;
			++cnt[t];
			sum += t;
		}
		int x = (2 * sum) / (3 * n - 2);
		double c;
		if (cnt[x])
			c = 1.0 / (cnt[x] + 1);
		else
			c = 1;
		printf("%d %.2f\n", x, c);
	}
	return 0;
}
