#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
string a, b, c;
bool dp[2050][2050];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> a >> b >> c) {
		memset(dp, false, sizeof(dp));
		dp[0][0] =  true;
		if (a.size() + b.size() != c.size()) {
			cout << "No" << endl;
			continue;
		}
		loop(i, a.size() + 1) {
			loop(j, b.size() + 1) {
				if (i > 0 && c[i + j - 1] == a[i - 1])
					dp[i][j] |= dp[i - 1][j];
				if (j > 0 && c[i + j - 1] == b[j - 1])
					dp[i][j] |= dp[i][j - 1];
			}
		}
		cout << (dp[a.size()][b.size()] ? "Yes" : "No") << endl;
	}
	return 0;
}
