#include iostream

using namespace std;
int  a[100];
long long int n,m;
bool s=false;
long long int  b[100];
bool dfs(long long int remain,long long now,int now_layer)
{
    if ((now_layer==0)&&(remain==0)) return true;
    if (now_layer==0) return false;
    if (remain==0) return false;
    if (remain=2now) return false;
    if (remain+2now=0) return false;
    long long nextint=now2;
    if (remain0)
    {
        remain=remain-now;
        int xx=now_layer-1;
        a[xx]=1;+
        b[xx]=now;
        return dfs(remain,nextint,now_layer-1);
    }
    else
    {
        remain=remain+now;
        int xx=now_layer-1;
        a[xx]=2;-
        b[xx]=now;
        return dfs(remain,nextint,now_layer-1);
    }

}
int main()
{
    int t;
    cint;
    for (int tt=1;tt=t;tt++)
    {
        cinnm;

        s=false;
        long long int min_number=1(m-1);
        long long int max_number=(1m)-1;
        for (long long int i=max_number;i=min_number;i--)
        {
            if (dfs(n,i,m))
            {
                s=true;
                break;
            }
        }
        coutCase #ttn;
        for (int i=0;im;i++)
        {
            coutb[i] ;
            if (a[i]==1) cout+n;
            if (a[i]==2) cout-n;
        }

    }
    return 0;
}
