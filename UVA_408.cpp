#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define size(s) (int)(x).size()

using namespace std;

const int MXN = 100001;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int STEP, MOD;

  while(cin >> STEP >> MOD){
    int a[MXN], i=0, START=0; 
    memset(a,0,sizeof(a));
    a[0]=1;
    
    for(i = 0; i < MOD-1; i++){
      START = (START + STEP) % MOD;
      if(a[START] != 0) break;
      else a[START]=1;
    }
    cout << setw(10) << STEP << setw(10) << MOD << "    ";
    (i == (MOD-1)) ? cout << "Good Choice\n\n" : cout << "Bad Choice\n\n";
  }

  return 0;
}
