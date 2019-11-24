#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+1);
  vector<int> B(N);
  for (int i=0; i<N+1; i++){
    cin >> A[i];
  }
  for (int i=0; i<N; i++){
    cin >> B[i];
  }
  int ans = 0;
  // 勇者が暇な方に行ったがためにどこかの街が救えないことになってはいけない。
  for (int i=0; i<N/2; i++){
    // 左端
    if (A[i] <= B[i]){
      B[i] -= A[i];
      ans += A[i];
      A[i] = 0;
      if (A[i+1] <= B[i]){
        B[i] -= A[i+1];
        ans += A[i+1];
        A[i+1] = 0;
      } else{
        A[i+1] -= B[i];
        ans += B[i];
        B[i] = 0;
      }
    } else{
      A[i] -= B[i];
      ans += B[i];
      B[i] = 0;
    }

    // 右端
    if (A[N-i+1] <= B[N-i])
  }
  return 0;
}
