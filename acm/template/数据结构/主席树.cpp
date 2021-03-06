#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+100;
int tree[maxn<<5],lson[maxn<<5],rson[maxn<<5],tot;
int T[maxn],a[maxn],Hash[maxn];
void buildtree(int &root,int l,int r)
{
    root=tot++;
    tree[root]=0;
    if(l==r)
    {
        return ;
    }
    int mid=(l+r)>>1;
    buildtree(lson[root],l,mid);
    buildtree(rson[root],mid+1,r);
}
void update(int &root,int l,int r,int pre,int x)
{
    root=tot++;
    lson[root]=lson[pre];
    rson[root]=rson[pre];
    tree[root]=tree[pre]+1;
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    if(x<=mid)
        update(lson[root],l,mid,lson[pre],x);
    else
        update(rson[root],mid+1,r,rson[pre],x);
}
int query(int l,int r,int x, int y,int k)
{
    cout<<"query "<<l<<" "<<r<<" "<<k<<endl;
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    int num=tree[lson[y]]-tree[lson[x]];
    if(k<=num)
        return query(l,mid,lson[x],lson[y],k);
    else
        return query(mid+1,r,rson[x],rson[y],k-num);
}
//int queryx(int l,int r,int x,int y,int k)
//{
//    //cout<<"queryx "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<k<<endl;
//    if(l==r)
//    {
//        return (tree[y]-tree[x]);
//    }
//    int mid=(l+r)>>1;
//    if(k<=mid)
//    {
//        return queryx(l,mid,lson[x],lson[y],k);
//    }
//    else
//    {
//        return (tree[lson[y]]-tree[lson[x]])+queryx(mid+1,r,rson[x],rson[y],k);
//    }
//}
int main()
{
    int n,q,l,r,k;
    scanf("%d%d",&n,&q);
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            Hash[i]=a[i];
        }
        tot=0;
        sort(Hash,Hash+n);
        int num=unique(Hash,Hash+n)-Hash;
        //cout<<"????????"<<endl;
        //cout<<num<<endl;
        buildtree(T[0],0,num-1);
        for(int i=0;i<n;i++)
        {
            a[i]=lower_bound(Hash,Hash+num,a[i])-Hash;
            //cout<<"a[i] "<<a[i]<<endl;
            update(T[i+1],0,num-1,T[i],a[i]);
        }
        while(q--)
        {
            scanf("%d%d%d",&l,&r,&k);
            cout<<query(0,num-1,l-1,r-1,k)<<endl;
        }
    }
    return 0;
}

