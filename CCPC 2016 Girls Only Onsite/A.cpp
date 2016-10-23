#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int T, n;

struct ballon
{
	int num;
	string color;
} ballons[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	auto cmp = [](ballon &a, ballon &b){return a.num > b.num;};
	while(T--) {
		cin >> n;
		loop(i, n) cin >> ballons[i].color >> ballons[i].num;
		sort(ballons, ballons + n, cmp);
		loop(i, n - 1) cout << ballons[i].color << " ";
		cout << ballons[n-1].color << endl;
	}
	
	return 0;
}
