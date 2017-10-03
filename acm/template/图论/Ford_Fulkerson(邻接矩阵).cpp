#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=550;
int vis[maxn];
int cap[maxn][maxn];
int n,m;
int dfs(int s,int t,int v)
{
    //cout<<"what happended?"<<endl;
    if(s==t)
        return v;
    vis[s]=1;
    for(int i=1;i<=n;i++)
    {
        //cout<<"???"<<endl;
        if(!vis[i]&&cap[s][i]>0)
        {
            int d=dfs(i,t,min(v,cap[s][i]));
            if(d>0)
            {
                cap[s][i]-=d;
                cap[i][s]+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int ans=0;
    for(;;)
    {
        memset(vis,0,sizeof(vis));
        int d=dfs(s,t,INF);
        if(d==0)
            return ans;
        ans+=d;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(cap,0,sizeof(cap));
        int u,v,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cap[u][v]+=w;
        }
        cout<<max_flow(1,n)<<endl;;
    }
    return 0;
}
s
