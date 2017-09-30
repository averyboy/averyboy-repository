#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char p[maxn],t[maxn];
int Next[maxn];
void get_Next(char *p)
{
    int k=0;
    int lenp=strlen(p);
    Next[0]=0;
    for(int i=1;i<lenp;i++)
    {
        while(k&&p[i]!=p[k])
        {
            k=Next[k-1];
        }
        if(p[i]==p[k])
            k++;
        Next[i]=k;
    }
    return ;
}
int kmp(char *p,char *t)
{
    int ans=0;
    int lenp=strlen(p);
    int lent=strlen(t);
    int k=0;
    for(int i=0;i<lent;i++)
    {
        while(k&&t[i]!=p[k])
        {
            k=Next[k-1];
        }
        if(t[i]==p[k])
            k++;
        if(k==lenp)
        {
            ans++;
            k=0;//可重复的话k=Newxt[k-1]
        }
    }
    return ans;
}
int main()
{
    while(~scanf("%s%s",p,t))
    {
        get_Next(p);
        for(int i=0;p[i];i++)
            cout<<Next[i]<<" ";
        cout<<endl;
        cout<<kmp(p,t)<<endl;
    }
    return 0;;
}

