/*
    Solved By my_devotion(Cadence of Accepted)
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define loop(i ,n) for(int i = 0, _ = n; i < _; ++i)
int a[1000];
int flag[1000];
bool visit[1000];
bool ff=false;
vector <vector <int> > v;
int n,m,q,p;
void dfs(int x)
{
    int nn=flag[x];
    int need=3-nn;
    for (int i=0;i<v[x].size();i++)
    {
        if (ff==true) return;
        int now=v[x][i];
        int now_flag=flag[now];
        if (now_flag==0)
        {
            flag[now]=need;
            dfs(now);
            continue;
        }
        if (now_flag!=need)
        {
            ff=true;
            return;
        }
    }
    return;
}
int main()
{
    while (scanf("%d %d %d %d",&n,&m,&p,&q)!=-1)
    {
        memset(flag,0,sizeof(flag));
        memset(visit,0,sizeof(visit));
        v.clear();
        ff=false;
        for (int i=0;i<n;i++)
        {
            vector <int> vv;
            v.push_back(vv);
        }
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            y--;
            visit[x]=true;
            visit[y]=true;
            v[x].push_back(y);
            v[y].push_back(x);
        }


        vector<int> v_good;
        vector<int> v_bad;
        for (int i=0;i<p;i++)
        {
            int x;
            scanf("%d",&x);
            x--;
            v_good.push_back(x);
            flag[x]=1;
        }
        for (int i=0;i<q;i++)
        {
            int x;
            scanf("%d",&x);
            x--;
            v_bad.push_back(x);
            if (flag[x]==1) ff=true;
            flag[x]=2;
        }

         if (ff)
        {
            printf("NO\n");
            continue;
        }
        for (int i=0;i<n;i++)
        {
           if ((visit[i]==false)&&(flag[i]==0)) ff=true;
        }
        if (ff)
        {
            printf("NO\n");
            continue;
        }
        for (int i=0;i<v_good.size();i++)
        {
            int now=v_good[i];
            if (flag[now]==2) ff=true;
            flag[now]=1;
            dfs(now);
            if (ff==true) break;
        }
        if (ff)
        {
            printf("NO\n");
            continue;
        }

        for (int i=0;i<v_bad.size();i++)
        {
            int now=v_bad[i];
            if (flag[now]==1) ff=true;
            flag[now]=2;
            dfs(now);
            if (ff==true) break;
        }
        if (ff)
        {
            printf("NO\n");
            continue;
        }
        for (int i=0;i<n;i++)
        {
            if (flag[i]==0)
            {
                flag[i]=1;
                dfs(i);
            }
            if (ff==true) break;
        }
        if (ff)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");

    }
    return 0;
}

