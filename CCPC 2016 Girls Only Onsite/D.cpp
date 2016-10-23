#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
const int M = 120;
int h, m, s, a;

int solve(int u, int v, int a)
{
	int d, ans;
	d = (v + M * 360 - u) % (M * 360);
	if (d >= M * 180)
	{
		if (a * M < 360 * M - d)
			ans = v + (d - a * M) / 11;
		else
			ans = v + (d - (360 - a) * M) / 11;
	}
	else
	{
		if (a * M <= d)
			ans = v + (d - a * M) / 11;
		else
			ans = v + (d + a * M) / 11;
	}
	return ans;
}

int main()
{
	int _i = 1;
	while (~scanf("%d:%d:%d\n%d", &h, &m, &s, &a)) {
		int hh, mm, ss;
		int u = (12 * (m * 60 + s + 1)) % (M * 360);
		int v = h * 3600 + m * 60 + s + 1;
		int ans = solve(u, v, a);
		hh = ans / 3600 % 12;
		mm = ans / 60 % 60;
		ss = ans % 60;
		printf("Case #%d: %02d:%02d:%02d\n", _i++, hh, mm, ss);
	}
	return 0;
}
