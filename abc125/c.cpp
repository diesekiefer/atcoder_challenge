#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
  if (a > b){
    if (b == 0){
      return a;
    }
    return gcd(b, a % b);
  } else{
    if (a == 0){
      return b;
    }
    return gcd(a, b % a);
  }
}

int main(){
  int N;
  cin >> N;
  int A[N];
  for (int i=0; i<N; i++){
    cin >> A[i];
  }

  // if (N == 2){
  //   if (A[0] < A[1]){
  //     cout << A[1] << endl;
  //   } else{
  //     cout << A[0] << endl;
  //   }
  //   return 0;
  // }
  //
  // int output = 0;
  // // 一つのぞいた時の最大公約数
  // for (int j=0; j<N; j++){
  //   int tmp = 0;
  //   if (j==0){
  //     tmp = A[1];
  //     for (int i=2; i<N; i++){
  //       tmp = gcd(tmp, A[i]);
  //     }
  //   } else{
  //     tmp = A[0];
  //     for (int i=1; i<N; i++){
  //       if (i == j){
  //         continue;
  //       } else{
  //         tmp = gcd(tmp, A[i]);
  //       }
  //     }
  //   }
  //   if (output < tmp){
  //     output = tmp;
  //   }
  // }

  // 順番に公約数を求めるとはやい
  int L[N+1];
  int R[N+1];
  L[0] = 0;
  R[N] = 0;

  for (int i=0; i<N; i++){
    L[i+1] = gcd(L[i], A[i]);
  }
  for (int i=N-1; i>=0; i--){
    R[i] = gcd(R[i+1], A[i]);
  }

  int output = 0;
  for (int i=0; i<N; i++){
    int m = gcd(L[i], R[i+1]);
    if (output < m){
      output = m;
    }
  }
  cout << output << endl;
  return 0;
}
