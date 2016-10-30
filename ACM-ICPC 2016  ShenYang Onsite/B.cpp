#include <bits/stdc++.h>

using namespace std;

map<char, int> cnt;
string s;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		cnt.clear();
		for(auto c: s)
			++cnt[c];
		cout << cnt['H'] + 12 * cnt['C'] + 16 * cnt['O'] << endl;
	}
	return 0;
}
