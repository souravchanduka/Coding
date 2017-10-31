#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<int> G[N];
set<int> ans;
int vis[N];
int par[N];
int coun[N];
vector<int> lev[N];
int lev1[N];
int lev2[N];
int main()
{
    queue<int> a;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int x,y;
    cin>>x>>y;
    a.push(x);
    vis[x]=1;
    set<int> s;
    while(!a.empty())
    {
        int u=a.front();a.pop();
        if(u==y)
            break;

        for(int i=0;i<G[u].size();i++)
        {  
           // if(vis[G[u][i]])
            
           //   continue;
              if(!vis[G[u][i]])
                   lev1[G[u][i]]=lev1[u]+1;
                if(G[u][i]==y &&lev1[u]!=lev1[y])
                    s.insert(u);    
            if(vis[G[u][i]])
                continue;
            vis[G[u][i]]=1;
            par[G[u][i]]=u;
            a.push(G[u][i]);
         //   lev1[G[u][i]]=lev1[u]+1;
        }

    }
   set<int>::iterator it;
   for( it=s.begin();it!=s.end();it++)
   {int a;
       a=*it;
       while(a!=x)
       {
           coun[a]++;
           a=par[a];
       }
   }
   int min1=1e5+1;
   for(int i=1;i<=n;i++)
       if(coun[i]==s.size() && s.size()!=0)
           min1=min(min1,i);
   if(min1>1e5)
       cout<<-1<<endl;
   else
       cout<<min1<<endl;
    return 0;
}