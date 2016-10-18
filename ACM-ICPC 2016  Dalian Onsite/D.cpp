/*
    Solved By my_devotion(Cadence of Accepted)
*/

#include <bits/stdc++.h>

using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
typedef long long int64;
int64 k;
int gcd(int a,int b)
{
    while (b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        int g=gcd(n,m);
        int a=n/g;
        int b=m/g;
        long long int delta2=a*a-4*b;
        int delta=sqrt(delta2);
        long long int dd=delta*delta;
        if (dd!=delta2)
        {
         printf("No Solution\n");
         continue;
         }
        int ans1=(a-delta)/(2);
        int ans2=(a+delta)/2;
        if (ans1<0)
        {
            int k2=a-ans2;
            int k1=ans2;
            int x1=k1*g;
            int x2=k2*g;
            if (x1>x2) swap(x1,x2);
            if (x1+x2!=n) printf("No Solution\n");
                    else  printf("%d %d\n",x1,x2);
        }
        else
        {
            int k1=ans1;
            int k2=a-ans1;
            int x1=k1*g;
            int x2=k2*g;
            if (x1>x2) swap(x1,x2);
            if (x1+x2!=n) printf("No Solution\n");
                    else  printf("%d %d\n",x1,x2);
        }

    }

    return 0;
}
