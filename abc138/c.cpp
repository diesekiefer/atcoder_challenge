#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }

  double ans = 1;
  for (int i=0; i<N; i++){
    double inv = 1 / (double)A[i];
    ans *= exp(inv);
  }
  ans = 1 / (log(ans));
  cout << ans << endl;
  return 0;
}
