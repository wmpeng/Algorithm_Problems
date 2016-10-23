#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
const int MAXN = 1050;
int T;
string s[MAXN];
const string GIRL = "girl", CAT = "cat";
bool visited[MAXN][MAXN];
int girls, cats, n, m;


inline bool isokay(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}


void dfs(int x, int y, int k, bool isgirl)
{
	if (!isokay(x, y) || s[x][y] != (isgirl? GIRL[k]: CAT[k]))
		return;
	visited[x][y] = true;
	if (isgirl && k == 3) {
		++girls;
		return;
	}
	if (!isgirl && k == 2) {
		++cats;
		return;
	}
	dfs(x + 1, y, k + 1, isgirl);
	dfs(x, y + 1, k + 1, isgirl);
	dfs(x - 1, y, k + 1, isgirl);
	dfs(x, y - 1, k + 1, isgirl);
}


int main()
{
	cin >> T;
	while (T--) {
		cin >> n >> m;
		loop(i, n) cin >> s[i];
		memset(visited, false, sizeof(visited));
		girls = cats = 0;
		loop(i, n) loop(j, m) {
			if (!visited[i][j]) {
				if (s[i][j] == 'g')
					dfs(i, j, 0, true);
				else if (s[i][j] == 'c')
					dfs(i, j, 0, false);
			}
		}
		cout << girls << " " << cats << endl;
	}
	return 0;
}
