#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct Trie
{
    Trie *pre,*Next[26];
    int val;
    Trie()
    {
        pre=0;
        val=0;
        memset(Next, 0, sizeof(Next));
    }
}*root,*last;
Trie TriePool[maxn * 2], *cur;

void init()
{
    cur = TriePool;
    root = last = cur++;
}

void extend(int w)
{
    Trie *p = last, *np = cur++;
    np->val = p->val + 1;
    while (p&&!p->Next[w]) p->Next[w] = np, p = p->pre;
    if (!p) np->pre = root;
    else
    {
        Trie *q = p->Next[w];
        if (p->val + 1 == q->val)
        {
            np->pre = q;
        }
        else
        {
            Trie *nq = cur++;
            memcpy(nq->Next, q->Next, sizeof q->Next);
            nq->val = p->val + 1;
            nq->pre = q->pre;
            q->pre = nq;
            np->pre = nq;
            while (p&&p->Next[w] == q)
            {
                p->Next[w] = nq, p = p->pre;
            }
        }
    }
    last = np;
}

char stra[maxn], strb[maxn];

int main()
{
    int n;
    //while (~scanf("%d",&n))
    while(~scanf("%s%s",stra,strb))
    {
        //while(n--)
        {
            init();
            memset(TriePool, 0, sizeof(TriePool));
            //scanf("%s%s",stra,strb);
            int lena = strlen(stra);
            for (int i = 0; i < lena; i++)
            {
                extend(stra[i] - 'a');
            }
            //cout<<stra<<" "<<strb<<endl;
            int ans = 0;
            int lenb = strlen(strb);
            Trie *p = root;
            int len = 0;
            for (int i = 0; i < lenb; i++)
            {
                if (p->Next[strb[i] - 'a'])
                {
                    len++;
                    ans = max(ans, len);
                    p = p->Next[strb[i] - 'a'];
                }
                else
                {
                    while (p&&!p->Next[strb[i] - 'a'])
                    {
                        p = p->pre;
                    }
                    if (!p)
                    {
                        p = root;
                        len = 0;
                    }
                    else
                    {
                        len = p->val + 1;
                        ans = max(len, ans);
                        p = p->Next[strb[i] - 'a'];
                    }
                }
            }
        printf("%d\n", ans);
        }
    }
    return 0;
}
