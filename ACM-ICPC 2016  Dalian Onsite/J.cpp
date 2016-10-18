/*

    简单的进制转换。裁判一开始给RE真是醉了。

    Solved By HTTP404(Cadence of Accepted)
*/

#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0, _ = n; i < _; ++i)
typedef long long int64;
int64 n, ans, a;
int64 check(int64 x)
{
    int64 y = 0;
    while (x != 0) {
        int64 r = x & ff;
        if (r == 97)
            ++y;
        x >>= 8;
    }
    return y;
}


int main()
{
    while (cin >> n) {
        ans = 0;
        while (n--) {
            cin >> a;
            ans += check(a);
        }
        cout << ans << endl;
    }
    return 0;
}
