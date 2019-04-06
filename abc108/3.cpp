#include <bits/stdc++.h>
using namespace std;

int rec(int N, int K){
  // N までで条件を満たす個数を返す
  // N-1 までで条件を満たすやつを それ以外に分ける
  // そうすると, a, b, c のどれかにNを含むものがそれ以外になる
  if (N == 0){
    return 0;
  }
  int out = 0;
  // 全部 N の場合
  if ((2 * N) % K == 0){
    out++;
    // 二つ N が成立するならば全部Nでも成立している
    // それ以外で成立するものが存在するかどうか
    for (int i=1; i < N; i++){
      if ((N + i) % K == 0){
        out += 3;
      }
    }
  }
  // 一つ N の場合
  
  for (int i=1; i<N; i++){
    if ((2 * i) % K == 0 && (i + N) % K == 0){
      out += 3;
    }
    for (int j=i+1; j<N; j++){
      if ((i+j) % K == 0 && (i + N) % K == 0 && (j + N) % K == 0){
        out += 6;
      }
    }
  }
  return rec(N-1, K) + out;
}

int main(){
  int N, K;
  cin >> N;
  cin >> K;
  // 如何に時間短縮をするか
  // 再帰でやる問題ではないだろうか？
  // a + b = l * K
  // b + c = m * K
  // c + a = n * K
  // 2 (a + b + c) = (l + m + n) * K

  cout << rec(N, K) <<  endl;
  return 0;
}
