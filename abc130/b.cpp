#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for (int i=0; i<N; i++){
    cin >> L[i];
  }

  int D = 0;
  int i = 0;
  int ans = 0;
  while(D <= X){
    if (i > N) break;
    ans++;
    D += L[i];
    i++;
  }
  cout << ans << endl;
  return 0;
}
