#include <bits/stdc++.h>
using namespace std;

vector < pair < int, pair < int, int >>>Edges;
int *parent;
int no_vertices;

vector<int> neighbours(int v){
    vector <int> res;
    for(int i=0;i<Edges.size();i++)
    if(Edges[i].second.first==v)
    res.push_back(Edges[i].second.second);
    return res;
}

vector<int> vertices(){
    vector<int> res;
    for(int i=0;i<Edges.size();i++){
        if(find(res.begin(),res.end(),Edges[i].second.first)==res.end())
        res.push_back(Edges[i].second.first);
        if(find(res.begin(),res.end(),Edges[i].second.second)==res.end())
        res.push_back(Edges[i].second.second);
    }
    return res;
}

int edge_weight(int v1, int v2){
    for(int i=0;i<Edges.size();i++)
    if(Edges[i].second.first==v1 && Edges[i].second.second==v2)
    return Edges[i].first ;
}

int contains_vertex(int v){
    for(int i=0;i<Edges.size();i++)
    if(Edges[i].second.first==v || Edges[i].second.second==v)
    return 1;
    return 0;
}

int contains_edge(int v1,int v2){
    for(int i=0;i<Edges.size();i++)
    if(Edges[i].second.first==v1 || Edges[i].second.second==v2)
    return 1;
    return 0;
}

int main ()
{
  int v1, v2, wgt;
  char ch='\0';
  cin >> no_vertices ;
  getchar();
  scanf("%c",&ch);
  while(ch!=EOF && ch!='\0'){
	  if(ch=='E'){
		    cin >> v1 >> v2 >> wgt;
		    Edges.push_back(make_pair(wgt,make_pair(v1, v2)));
		    getchar();
	  }
	  else if(ch=='N'){
	      scanf("%d",&v1);
	      vector<int> res = neighbours(v1);
	      for(int i=0;i<res.size();i++)
	      cout<<res[i]<<" ";
	      cout<<endl;
	      getchar();
	  }
	  else if(ch=='V'){
	      vector<int> res = vertices();
	      for(int i=0;i<res.size();i++)
	      cout<<res[i]<<" ";
	      cout<<endl;
	      getchar();
	  }
	  else if(ch=='W'){
	      scanf("%d %d",&v1,&v2);
	      printf("%d\n",edge_weight(v1,v2));
	      getchar();
	  }
	  else if(ch=='v'){
	      scanf("%d",&v1);
	      printf("%d\n",contains_vertex(v1));
	      getchar();
	  }
	  else if(ch=='e'){
	      scanf("%d %d",&v1,&v2);
	      printf("%d\n",contains_edge(v1,v2));
	      getchar();
	  }
	  
	  scanf("%c",&ch);

  }
  
  return 0;
}
