#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

int incX[] = {-1, 0, 1};
int incY[] = {0, -1, 0};
string incDir[] = {"left","forth","right"};
bool visited[8][8];
bool valid(int y, int x){if(!(y < 0 || y >= 8 || x < 0 || x >= 8)) return true; return false;}

void dfs(int y, int x, string a[], int pos){
  if(!(a[y][x] == 'I' || a[y][x] == 'E' || a[y][x] == 'H' || a[y][x] == 'O' || a[y][x] == 'V' || a[y][x] == 'A' || a[y][x] == '@' || a[y][x] == '#')) return;
  if(a[y][x] != '@' && a[y][x] != '#') cout << incDir[pos] << " "; else if(a[y][x] == '#') cout << incDir[pos] << "\n";
  visited[y][x] = true;
  for(int i=0; i<3; i++){
    int nY = incY[i]+y, nX = incX[i]+x;
    if(valid(nY,nX) && !visited[nY][nX]) dfs(nY, nX, a, i);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  while(q--){
    int n,m; cin >> n >> m;
    memset(visited, false, sizeof(visited));
    string a[n];
    pair<int,int> init[1];

    for(int i=0; i<n; i++){
      cin >> a[i];
      if(i == 0 || i == n-1){
        for(int j=0; j<m; j++){
          if(a[i][j] == '@') init[0] = make_pair(i,j);
        }
      }
    }
    dfs(init[0].first, init[0].second, a, 0); 
  }

  return 0;
}
