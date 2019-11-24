#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  int max = *max_element(A.begin(), A.end());
  int cnt = 0;
  int max_idx = 0;
  for (int i=0; i<N; i++){
    if (A[i] == max){
      cnt++;
      max_idx = i;
    }
  }
  if (cnt > 1){
    for (int i=0; i<N; i++){
      cout << max << endl;
    }
  } else{
    A[max_idx] = 0;
    int max_next = *max_element(A.begin(), A.end());
    for (int i=0; i<N; i++){
      if (i == max_idx){
        cout << max_next << endl;
      } else{
        cout << max << endl;
      }
    }
  }
  return 0;
}
