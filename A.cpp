#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define size(s) (int)(x).size()

using namespace std;

const int MXN = 100001;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, c;

  while(cin >> n >> m >> c && n != 0){
    int res = (c==1) ? 1 : 0;
    cout << ((n-7) * (m-7) + res) / 2 << "\n";
  }
  
  return 0;
}
