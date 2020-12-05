#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 26

using namespace std;

int incX[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int incY[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int n;
bool visited[MAX][MAX];
bool valid(int y, int x){if(!(y < 0 || y >= n || x < 0 || x >= n)) return true; return false;}


void dfs(int y, int x, string a[]){
  visited[y][x] = true;
  for(int i=0; i<8; i++){
    int nY = incY[i] + y, nX = incX[i] + x;
    if(valid(nY,nX) && !visited[nY][nX] && a[nY][nX] != '0') dfs(nY,nX,a);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int index=0;
  while(cin >> n){
    string a[n]; memset(visited, false, sizeof(visited));
    for(int i=0; i<n; i++){
      cin >> a[i];  
    }
    int cnt=0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(!visited[i][j] && a[i][j] == '1'){
          dfs(i,j, a);
          ++cnt;
        } 
      }
    }
    printf("Image number %d contains %d war eagles.\n", ++index, cnt);
  }
  return 0;
}
