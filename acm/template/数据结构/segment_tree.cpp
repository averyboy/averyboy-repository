#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int tree[maxn<<2];
int lazy[maxn<<2];
void pushup(int root)
{
    tree[root]=tree[root<<1]+tree[root<<1|1];
    return ;
}
void pushdown(int root,int l,int r)
{
    if(lazy[root])
   {
        int mid=(l+r)>>1;
        tree[root<<1]=(mid-l+1)*lazy[root];
        tree[root<<1|1]=(r-mid)*lazy[root];
        lazy[root<<1]=lazy[root<<1|1]=lazy[root];
        lazy[root]=0;
   }
   return ;
}
void buildtree(int root,int l,int r)
{
    if(l==r)
    {
        scanf("%d",tree+root);
        return ;
    }
    int mid=(l+r)>>1;
    buildtree(root<<1,l,mid);
    buildtree(root<<1|1,mid+1,r);
    pushup(root);
}
void update(int root,int l,int r,int L,int R,int v)
{
    if(L<=l&&R>=r)
    {
        tree[root]=(r-l+1)*v;
        lazy[root]=v;
        return ;
    }
    pushdown(root,l,r);
    int mid=(l+r)>>1;
    if(L<=mid)
        update(root<<1,l,mid,L,R,v);
    if(R>mid)
        update(root<<1|1,mid+1,r,L,R,v);
    pushup(root);
}
int query(int root,int l,int r,int L,int R)
{
    if(L<=l&&R>=r)
    {
        return tree[root];
    }
    pushdown(root,l,r);
    int mid=(l+r)>>1;
    int ans=0;
    if(L<=mid)
        ans+=query(root<<1,l,mid,L,R);
    if(R>mid)
        ans+=query(root<<1|1,mid+1,r,L,R);
    return ans;
}
int main()
{
    int N,Q,num,l,r,v;
    while(~scanf("%d",&N))
    {
        buildtree(1,1,N);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%d",&num);
            if(num==0)
            {
                scanf("%d%d",&l,&r);
                cout<<query(1,1,N,l,r)<<endl;;
            }
            if(num==1)
            {
                scanf("%d%d%d",&l,&r,&v);
                update(1,1,N,l,r,v);
            }
        }
    }
    return 0;
}
