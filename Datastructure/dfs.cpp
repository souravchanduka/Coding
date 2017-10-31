#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100000];
void dfs(int u,int par)
{
  for(int i=0;i<graph[u].size();i++)
    if(graph[u][i]!=par)
      dfs(graph[u][i],u);
}
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1,-1);
  return 0;
}
