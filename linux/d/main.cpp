#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int N,dp[100010],l[100010],s[100010],M;
int lowbit(int k)
{
    return k&(-k);
}
int sum(int i)
{
    int ssum=0;
    while(i>0)
    {
        ssum+=s[i];
        i-=lowbit(i);
    }
    return ssum;
}
void cha(int i,int n,int lll)
{
    while(i<=lll)
    {
        s[i]+=n;
        i+=lowbit(i);
       // printf("%d\n",s[i]);
    }
}
void init(int n)
{
    int i;
    for(i=0;i<n;i++)
        dp[i]=1;
}
int lis(int a[],int n)
{
    int i,j,maxlen=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        {
            dp[i]=dp[i-1]+1;
        }
        else
            dp[i]=1;
        if(dp[i]>maxlen)
            maxlen=dp[i];
    }
    return maxlen;
}
int main()
{
    int T,maxl;
    int f[3],se[2];
    char shu[10];
    while(~scanf("%d",&T))
    {
        while(T--)
        {

            printf("Case#1:\n");
            memset(s,0,sizeof(s));
            scanf("%d",&N);
            for(int i=0;i<N;i++)
                scanf("%d",&l[i]);
           init(N);
           maxl=lis(l,N);
//          cout<<maxl<<endl;
           sort(l,l+N);
           for(int i=1;i<=maxl;i++)
           {
               cha(i,l[i-1],maxl);
           }
           scanf("%d",&M);
           for(int i=0;i<M;i++)
           {
               scanf("%s",shu);
               if(shu[0]=='f')
               {
                scanf("%d%d%d",&f[0],&f[1],&f[2]);
                {

                   //printf("%d%d%d\n",f[0],f[1],f[2]);
                   for(i=f[0];i<=f[1];i++)
                    cha(i,f[2],maxl);
                   for(i=0;i<maxl;i++)
                    cout<<s[i]<<endl;
                }
               }
               if(shu[0]=='s')
               {
                   scanf("%d%d",&se[0],&se[1]);
                   if(se[0]==se[1])
                    printf("%d\n",se[0]);
                   else
                    printf("%d\n",sum(se[0]-se[1]));

               }
           }
        }
    }
    return 0;
}
