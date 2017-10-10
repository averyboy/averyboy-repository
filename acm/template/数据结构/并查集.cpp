#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fa[maxn];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    return ;
}
int getfa(int x)
{
   return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void join(int x,int y)
{
    int fax=getfa(x);
    int fay=getfa(y);
    if(fax!=fay)
        fa[fax]=fay;
    return ;
}
bool query(int x,int y)
{
    return getfa(x)==getfa(y);
}
int main()
{
    int n,m,p,u,v;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            join(u,v);
        }
        for(int i=0;i<p;i++)
        {
            scanf("%d%d",&u,&v);
            cout<<(query(u,v)?"Yes":"No")<<endl;
        }
    }
    return 0;
}

