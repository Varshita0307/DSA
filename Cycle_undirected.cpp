#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node, int parent, vector<int>g[], vector<bool> &vis)
{
    vis[node] = true;
    for(auto i:g[node])
    {
        if(!vis[i])
        {
            if(DFS(i,node,g,vis))
            return true;
        }
        else if (i!=parent)
        return true;
    }
    return false;
    
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> vis(V);
   for(int i=0;i<V;i++)
      if (!vis[i] && DFS(i,-1,g,vis))
          return true;
    
    return false;
   
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<isCyclic(adj,v)<<endl;
}
