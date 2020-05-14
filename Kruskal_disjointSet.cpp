//PseudoCode for Kruskal's ALgorithm using Disjoint Sets
//KRUSKAL(G):
//A = b
//For each vertex v b G.V:
//    MAKE-SET(v)
//For each edge (u, v) b G.E ordered by increasing order by weight(u, v):
//    if FIND-SET(u) b	  FIND-SET(v):       
//    A = A b* {(u, v)}
//    UNION(u, v)
//return A

#include <bits/stdc++.h>
using namespace std;

vector < pair < int, pair < int, int >>>Edges;
int *parent;
int no_vertices;


void MakeSet (int vertice)
{
  parent[vertice] = vertice;
}

int FindSet (int vertice)
{
  if (parent[vertice] != vertice)
    parent[vertice] = FindSet (parent[vertice]);
  return parent[vertice];
}

void Union (int vertice1, int vertice2)
{
  int root1 = FindSet (vertice1);
  int root2 = FindSet (vertice2);
  parent[root1] = root2;
}

void kruskal (){

  vector < pair < int, pair < int, int >>>MST;
  sort (Edges.begin (), Edges.end ());	//sorts in a non decreasing order
  for (int i = 0; i < Edges.size (); i++)
    {
      int x = FindSet (Edges[i].second.first);
      int y = FindSet (Edges[i].second.second);
      if (x != y)
	{
	  MST.push_back (Edges[i]);
	  Union (x, y);
	}
    }
    
  if (MST.size() != no_vertices-1)
  cout<<"Spanning Tree does not exist";
  for (int i = 0; i < MST.size (); i++)
    {
      cout <<'('<< MST[i].second.first << ','<< MST[i].second.second<<')';
      
      }
      
}

int main ()
{
  int v1, v2, wgt;
  char ch='\0';
  cin >> no_vertices ;
  parent = new int[no_vertices];
  for (int i = 0; i < no_vertices; i++)
    MakeSet (i);
  getchar();
  scanf("%c",&ch);
  while(ch!=EOF && ch!='\0'){
	  if(ch=='E'){
		    cin >> v1 >> v2 >> wgt;
		    Edges.push_back(make_pair(wgt,make_pair(v1, v2)));
		    getchar();
	  }
	  else if(ch=='\n')
	  break;
	  
	  scanf("%c",&ch);

  }
  
  kruskal ();
  return 0;
}
