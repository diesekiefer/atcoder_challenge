#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<int> Box(N);
  for (int i=0; i<N; i++){
    Box[i] = 0;
  }
  int cnt = 0;
  for (int i=N-1; i>=0; i--){
    int j=i;
    int sum = 0;
    while(j < N){
      sum += Box[j];
      j += i+1;
    }
    if ((A[i] % 2) != (sum % 2)){
      Box[i] = 1;
      cnt++;
    }
  }
  printf("%d\n",cnt);
  for (int i=0; i<N; i++){
    if (Box[i] == 1){
      printf("%d ", i+1);
    }
  }
  return 0;
}
