#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int tree[20][maxn];
int num[20][maxn];
int sorted[maxn];
void init(int n)
{
    sort(sorted,sorted+n);
    memset(num,0,sizeof(num));
    return ;
}
void buildtree(int dep,int l,int r)
{
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    int sam=0;
    for(int i=l;i<=mid;i++)
        if(sorted[i]==sorted[mid])
            sam++;
    int lst=l,rst=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(i==l)
            num[dep][i]=0;
        else
            num[dep][i]=num[dep][i-1];
        if(tree[dep][i]<sorted[mid])
        {
            tree[dep+1][lst++]=tree[dep][i];
            num[dep][i]++;
        }
        else if(tree[dep][i]==sorted[mid]&&sam)
        {
            tree[dep+1][lst++]=tree[dep][i];
            num[dep][i]++;
            sam--;
        }
        else if(tree[dep][i]==sorted[mid])
        {
            tree[dep+1][rst++]=tree[dep][i];
        }
        else
        {
            tree[dep+1][rst++]=tree[dep][i];
        }
    }
    buildtree(dep+1,l,mid);
    buildtree(dep+1,mid+1,r);
}
int query(int dep,int L,int R,int lq,int rq,int k)
{
    if(L==R)
    {
        return tree[dep][L];
    }
    int mid=(L+R)>>1;
    int lnum=(lq==L?0:num[dep][lq-1]);//lq前进入左子树个个数
    int rnum=num[dep][rq];//rq前进入左子树个个数
    int lrnum=rnum-lnum;//lq-rq前进入左子树个个数
    if(k<=lrnum)
        return query(dep+1,L,mid,L+lnum,L+rnum-1,k);//(因为每个区间数字相对顺序没变，所以更新小区间时区间起始位置为lq前进入左子树的下一个位置即为L+num[dep][l+1],末位置为rq前进入左子树的个数)
    else
        return query(dep+1,mid+1,R,mid+1+(lq-L-lnum),mid+(rq-L+1-rnum),k-lrnum);//(与左子树同理,区间在右子树的起始位置为L(mid+1)+l之前进入左子树的个数，末位置为L(mid+1)+rq之前静茹右子树的个数)
}
//void debug(int n)
//{
//    cout<<"TREE"<<endl;
//    for(int j=0;j<ceil(log(n)/log(2));j++)
//    {
//        {
//            for(int i=0;i<n;i++)
//                cout<<tree[j][i]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<"NUM"<<endl;
//    for(int j=0;j<ceil(log(n)/log(2));j++)
//    {
//        {
//            for(int i=0;i<n;i++)
//                cout<<num[j][i]<<' ';
//        }
//        cout<<endl;
//    }
//    return ;
//}
int main()
{
    int n,m,l,r,k;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        init(n);
        buildtree(0,0,n-1);
        //debug(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&l,&r,&k);
            cout<<query(0,0,n-1,l-1,r-1,k)<<endl;
        }
    }
    return 0;
}

