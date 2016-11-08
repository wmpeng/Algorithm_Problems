/*
    
    如果是实数的话，另每个数尽可能接近于e。
    整数不重复的话，拆成2，3，4，5，6，7.... 余下的往回家，最后的结果肯定是pi[l1, r1) * pi[l2, r2)的形式。
    直接乘会TLE，用线段树来预处理一下[l, r)的乘积，这样查询只需log(n)。
    也可以预处理一下前缀积，然后解出模1000000007的乘法逆元。

    Solved By wmp(Cadence of Accepted)
*/

#include <bits/stdc++.h>
#pragma comment(linker,"/STACK:32000000")
#define MOD 1000000007
using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int t;
int x1;
long long x;

struct Tnode {
    int a, b;
    long long q = 1;
} node[600500];

class SegTree
{
public:

    long long build(int a, int b, int idx = 1)
    {
        node[idx].a = a;
        node[idx].b = b;
        if (a + 1 < b) {
            long long x = build(a, (a+b)/2, idx*2);
            long long y = build((a+b)/2, b, idx*2 + 1);
            node[idx].q = x*y%MOD;
        } else {
            node[idx].q = a;
            return node[idx].q;
        }
    }

    void query(int c, int d, long long& q, int idx = 1)
    {
        if(c <= node[idx].a && node[idx].b <= d) {
            q = (q * node[idx].q) % MOD;
            return;
        }

        if(c < (node[idx].a + node[idx].b) / 2) {
            query(c, d, q, idx*2);
        }
        if(d > (node[idx].a + node[idx].b) / 2) {
            query(c, d, q, idx*2 + 1);
        }
    }
};

SegTree st;

int main()
{
    long long i,j,n;
    long long sum;
    long long cha;
    long long ans=1;
    long long temp1=1;
    int ans1;
    double SQRT;
    scanf("%d",&t);
    st.build(2, 150000);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&x1);
        x=x1;
        //x = (rand()%int(1e9))+1;
        //cout <<"x:" <<x << endl;
        ans=1;
        temp1=1;
        if(x<=4)
        printf("%d\n",x);
        if(x>4)
        {
            SQRT=sqrt(9+8*x);
            n=(double(-1)+SQRT)/2.0;
            sum=0.5*(n+1)*n+0.001-1;
            cha=x-sum;
            //cout<<cha<<" "<<n<<endl;
            if(cha==0)
            {
//            for(j=2;j<=n;j++)
//            {
//                ans*=j;
//                ans%=MOD;
//            }
                st.query(2,n+1,ans);


            }
            else if(cha !=n)
            {
//            for(j=2;j<=n-cha;j++)
//            {
//                ans*=j;
//                ans%=MOD;
//            }
            st.query(2,n-cha+1,ans);
//            for(;j<=n;j++)
//            {
//                ans*=j+1;
//                ans%=MOD;
//            }
            st.query(n-cha+2,n+1+1,temp1);
            ans*=temp1;
            ans%=MOD;
            }
            else
            {
//                for(j=2;j<=n-1;j++)
//                {
//                    ans*=j+1;
//                    ans%=MOD;
//                }
                st.query(3,n+1,ans);
                ans*=n+2;
                ans%=MOD;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
