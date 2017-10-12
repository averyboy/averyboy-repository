    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1e5+10;
    struct Rank
    {
        int pos,num,time;
        bool operator==(Rank r) const
        {
            return pos==r.pos;
        }
        bool operator<(Rank r) const
        {
                if(num==r.num&&time==r.time)
                    return pos==1?false:pos<r.pos;
                else
                {
                        return num==r.num?time>r.time:num<r.num;
                }
        }
    }r[maxn];
    set<Rank>st;
    set<Rank>::iterator iter;
    int main()
    {
        int n,m,u,v;
        while(~scanf("%d%d",&n,&m))
        {
            memset(r,0,sizeof(r));
            st.clear();
            for(int i=1;i<=n;i++)
            {
                r[i].pos=i;
            }
            for(int i=0;i<m;i++)
            {
                scanf("%d%d",&u,&v);
                if(u==1)
                {
                    r[1].num++;
                    r[1].time+=v;
                    /*for(iter=st.begin();iter!=st.end();)
                    {
                        if(*iter<r[1]||(iter->num==r[1].num&&iter->time==r[1].time))
                        {
                            st.erase(iter++);
                        }
                        else
                            break;
                    }*/
                    while(!st.empty())
                    {
                        iter=st.begin();
                        if(*iter<r[1]||(iter->num==r[1].num&&iter->time==r[1].time))
                            st.erase(iter);
                        else
                            break;
                    }
                }
                else
                {
                    iter=st.find(r[u]);
                    if(iter!=st.end()&&*iter==r[u])
                    {
                        //cout<<"you"<<endl;
                        st.erase(iter);
                        r[u].num++;
                        r[u].time+=v;
                        st.insert(r[u]);
                    }
                    else
                    {
                        //cout<<"noy ok"<<endl;
                        r[u].num++;
                        r[u].time+=v;
                        if(r[1]<r[u])
                            st.insert(r[u]);
                    }
                }
                cout<<st.size()+1<<endl;
            }
        }
        return 0;
    }
