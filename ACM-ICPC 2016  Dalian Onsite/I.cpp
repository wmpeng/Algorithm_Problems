/*

    计算三角形面积。

    Solved By wmp(Cadence of Accepted)
*/


#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0, _ = n; i < _; ++i)
int n, d, i, angle;
double ans, temp;

int main()
{
    while (cin >> n >> d)
    {
        ans = 0;
        while (n--) {
            cin >> angle;
            ans += sin((double(angle)) / 180 * acos(-1.0));
        }
        ans *= d * d * 0.5;
        printf("%.3lf\n", ans);
    }
    return 0;
}
