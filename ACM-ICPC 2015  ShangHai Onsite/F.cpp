#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str[1005];

void peng()
{
    int location[26];
    int ans=10000000;
    int i;
    for(i=0;i<=25;i++)
        location[i]=-100000;
    for(i=1;str[i]!=0;i++)
    {
        if(i-location[str[i]-'a']<ans)
        {
            ans=i-location[str[i]-'a'];
        }
        location[str[i]-'a']=i;
    }
    if(ans>10000)
        ans=-1;
    printf("%d\n",ans);
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",str+1);
        printf("Case #%d: ",i);
        peng();
    }
    return 0;
}
