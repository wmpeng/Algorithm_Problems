/*

    经典的概率问题，抽奖问题，和取的先后次序无关。
    k + 1 为奇数时，在所有的组合情况中，先手方取到红球有C(k/2 + 1, k + 1)种可能，后手方有C(k/2 - x, k + 1)种可能，先手优势。
    k + 1 为偶数时, 先后手均为C((k+1)/2, k + 1)，均势。

    Solved By HTTP404(Cadence of Accepted)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(cin >> k)
        cout << (k & 1? 0: 1) << endl;
    return 0;
}
