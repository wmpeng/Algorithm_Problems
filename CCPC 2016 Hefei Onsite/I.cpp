#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
typedef unsigned long long uint64;

uint64 l, r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		cin >> l >> r;
		if(l == r) {
			cout << l << endl;
			continue;
		}
		uint64 x = 1ull << 63;
		while(!(x & r) || l & x) {
			x >>= 1;
		}
		while(x) {
			l |= x;
			x >>= 1;
		}
		cout << l << endl;
	}
	return 0;
}
