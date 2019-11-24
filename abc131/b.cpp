#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, L;
  cin >> N >> L;

  // 最小の価値は L 最大の価値は L + N -1
  // ゼロのりんごが存在するのは　L < 0 かつ |L| < N
  int ans = 0;
  if (L < 0){
    if (-L < N){
      for(int i=0; i<N; i++){
        ans += L + i;
      }
    } else{
      // 価値は全部負
      for (int i=0; i<N-1; i++){
        ans += L + i;
      }
    }
  } else{
    // 価値は全部正
    for (int i=1; i<N; i++){
      ans += L + i;
    }
  }
  cout << ans << endl;
  return 0;
}
