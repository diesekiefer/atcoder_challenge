#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> P(n);
  for (int i=0; i<n; i++){
    cin >> P[i];
  }
  int ans = 0;
  for (int i=1; i<n-1; i++){
    if ((P[i-1] < P[i] && P[i] < P[i+1]) || (P[i+1] < P[i] && P[i] < P[i-1])){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
