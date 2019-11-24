#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++){
    cin >> H[i];
  }
  // H[i-1] - H[i] > 2 の場合不可能？
  string ans = "Yes";
  int h = H[N-1];
  for (int i=N-2; i>=0; i--){
    if (H[i] - h > 1){
      ans = "No";
      break;
    } else if (H[i] - h == 1){
      // H[i]を一段下げればよい
      h = H[i] - 1;
    } else{
      h = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}
