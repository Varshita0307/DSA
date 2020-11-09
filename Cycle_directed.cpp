#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<int> adj[],bool vis[], bool rec[])
{
  
    vis[node]=true;
    rec[node]=true;
    for(auto i:adj[node])
    { 
        if(!vis[i] &&  DFS(i,adj,vis,rec))
        {
            return true;
        }
        else{
            if(rec[i])
            return true;
        }
    }
    
    rec[node]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V];
    bool rec[V];
    for(int  i=0;i<V;i++)
    {
        vis[i]=false;
        rec[i]= false;
    }
    
    for(int i =0;i<V;i++)
    {  if(!vis[i]){
      if(DFS(i,adj,vis,rec))
      return true;
    }
    }
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
    }
    cout<<isCyclic(v,adj)<<endl;
}
