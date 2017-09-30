#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char str[maxn];
struct Trie
{
    Trie *Next[26];
    int cnt;//以当前字符串为前缀的个数
    bool word;//是否为完整子串
    Trie()
    {
        memset(Next,NULL,sizeof(Next));
        cnt=0;
        word=false;
    }
}*root;
void insert_str(char* str)
{
    Trie* p=root;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        if(p->Next[num]==NULL)
            p->Next[num]=new Trie();
        p=p->Next[num];
        p->cnt++;
    }
    p->word=true;
    return ;
}
int query(char *str)
{
    Trie *p=root;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        if(p->Next[num])
        {
            p=p->Next[num];
        }
        else
            return 0;
    }
    return p->cnt;
}
int  main()
{
    int n,q;
    root =new Trie();
    while(~scanf("%d%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert_str(str);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%s",str);
            cout<<query(str)<<endl;
        }
    }
    return 0;
}

