#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 101

using namespace std;

int n;
int incX[] = {-1, 0, 1, 0};
int incY[] = {0, -1, 0, 1};
bool visited[MAX][MAX];
bool valid(int y, int x){if(!(y < 0 || y >= n || x < 0 || x >= n)) return true; return false;}

void dfs(int y, int x, int index, string a[], int len){
  if(!valid(y,x) || visited[y][x] || a[y][x] == '.' || len > n/2) return;
  visited[y][x] = true;
  if(index == 0) dfs(incY[0]+y, incX[0]+x, 0, a, len+1);
  else if(index == 1) dfs(incY[1]+y, incX[1]+x, 1, a, len+1);
  else if(index == 2) dfs(incY[2]+y, incX[2]+x, 2, a, len+1);
  else if(index == 3) dfs(incY[3]+y, incX[3]+x, 3, a, len+1);
  else{
    for(int i=0; i<4; i++){
      int nY = incY[i] + y, nX = incX[i] + x;
      dfs(nY, nX, i, a, len+1); 
    }
  } 
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  for(int k=0; k<q; k++){
    cin >> n;
    string a[n]; memset(visited, false, sizeof(visited));
    int cnt=0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(!visited[i][j] && a[i][j] == 'x'){
          dfs(i,j,-1,a,1); ++cnt;
        }
      }
    }
    printf("Case %d: %d\n", k+1, cnt);
  }

  return 0;
}
