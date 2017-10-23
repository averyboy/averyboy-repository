#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int vis[maxn];
int match[maxn];
int head[maxn];
struct Edge
{
    int to;
    int Next;
    //int w;
}e[maxn<<1];
int cnt;
void add(int u,int v)
{
    //e[cnt].w=w;
    e[cnt].to=v;
    e[cnt].Next=head[u];
    head[u]=cnt++;
    return ;
}
int dfs(int u)
{
    for(int i=head[u];i;i=e[i].Next)
    {
        int v=e[i].to;
        if(!vis[v])
        {
            vis[v]=1;
            if(!match[v]||dfs(match[v]))
            {
                match[v]=u;
                match[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!match[i])//注意是无向边，需要判断是否已经匹配
        {
            memset(vis,0,sizeof(vis));
            ans+=dfs(i);
        }
    }
    return ans;
}
int main()
{
    int n,m,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        memset(match,0,sizeof(match));
        memset(head,0,sizeof(head));
        cnt=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);//无向边
            add(u,v);
            add(v,u);
        }
        cout<<hungary(n)<<endl;
    }
    return 0;
}

