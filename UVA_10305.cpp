#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
list<int> topSort;

void dfs(int node){
  visited[node] = true;
  for(int i=0; i<sz(adj[node]); i++){
    int child = adj[node][i];
    if(!visited[child]) dfs(child);
  }
  topSort.push_front(node);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while(cin >> n >> m && (n !=0 || m !=0)){
    int from, to;
  
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    topSort.clear();

    for(int i=0; i<m; i++){
      cin >> from >> to;
      adj[from-1].push_back(to-1);
    }
    
    for(int i=0; i<n; i++){
      if(!visited[i]) dfs(i);
    }
    for(auto &x : topSort){
      printf("%d ", x+1);
    }
    putchar('\n');
  }
  return 0;
}
