#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char str[maxn];
struct Trie
{
    Trie *Next[26];
    Trie *fail;
    int word;
    Trie()
    {
        memset(Next,NULL,sizeof(Next));
        fail=NULL;
        word=0;
    }
}*root;
void insert_str(char *str)
{
    Trie *p=root;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        if(p->Next[num]==NULL)
        {
            p->Next[num]=new Trie();
        }
        p=p->Next[num];
    }
    p->word++;
    return ;
}
void get_fail()
{
    Trie *p=root,*q;
    queue<Trie*>qe;
    qe.push(p);
    while(!qe.empty())
    {
        p=qe.front();
        qe.pop();
        for(int i=0;i<26;i++)
        {
            if(p->Next[i])
            {
                if(p==root)
                {
                    p->Next[i]->fail=root;
                }
                else
                {
                    q=p->fail;
                    while(q!=NULL)
                    {
                        if(q->Next[i]!=NULL)
                        {
                            p->Next[i]->fail=q->Next[i];
                            break;
                        }
                        q=q->fail;
                    }
                    if(q==NULL)
                        p->Next[i]->fail=root;
                }
                qe.push(p->Next[i]);
            }
        }
    }
    return ;
}
int query(char *str)
{
    int ans=0;
    Trie *p=root,*q;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        while(p->Next[num]==NULL&&p!=root)
        {
            p=p->fail;
        }
        p=p->Next[num]==NULL?root:p->Next[num];
        q=p;
        while(q)//在计算结果时可能存在一直不失配的情况，但存在更短的字符串出现过，所以应该往后跳计算并将计算过的置为0避免重复计算
        {
            ans+=q->word;
            q->word=0;
            q=q->fail;
        }
    }
    return ans;
}
void delete_trie(Trie* root)
{
    Trie *p=root;
    for(int i=0;i<26;i++)
    {
        if(p->Next[i])
        {
            delete_trie(p->Next[i]);
        }
    }
    delete p;
    return ;
}
int main()
{
    int T,n;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            root=new Trie();
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%s",str);
                //cout<<str<<endl;
                insert_str(str);
            }
            //cout<<"okokokoko"<<endl;
            get_fail();
            scanf("%s",str);
            cout<<query(str)<<endl;
            delete_trie(root);
        }
    }
    return 0;
}

