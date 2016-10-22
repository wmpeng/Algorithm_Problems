#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0, _ = n; i < _; ++i)
typedef long long int64;
int T;
string s;
vector<int64> b;

int main()
{
    cin >> T;
    loop(case_i, T) {
        cin >> s;
        b.clear();
        int64 cnt = 1, orig = 0;
        char last = s[0];
        b.push_back(0);

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == last) cnt++;
            else
            {
                orig += cnt * cnt;
                b.push_back(cnt);
                cnt = 1;
            }
            last = s[i];
        }
        b.push_back(cnt);
        orig += cnt * cnt;
        b.push_back(0);
        int64 ans = orig;
        int64 temp;
        for (int i = 1; i < b.size() - 2; ++i)
        {
            if (b[i] == 1)
                temp = (b[i + 1] + b[i - 1] + 1) * (b[i + 1] + b[i - 1] + 1) - 1 - b[i + 1] * b[i + 1] - b[i - 1] * b[i - 1];
            else
                temp = (b[i + 1] - 1) * (b[i + 1] - 1) + (b[i] + 1) * (b[i] + 1) - b[i + 1] * b[i + 1] - b[i] * b[i];
            ans = max(ans, orig + temp);
            if (b[i + 1] == 1)
                temp = (b[i] + b[i + 2] + 1) * (b[i] + b[i + 2] + 1) - 1 - b[i] * b[i] - b[i + 2] * b[i + 2];
            else
                temp = (b[i] + 1) * (b[i] + 1) + (b[i + 1] - 1) * (b[i + 1] - 1) - b[i] * b[i] - b[i + 1] * b[i + 1];
            ans = max(ans, orig + temp);
        }
        printf("Case #%d: %I64d\n", case_i + 1, ans);
    }
    return 0;
}
