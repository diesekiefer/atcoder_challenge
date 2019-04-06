#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  // 偶数の数 奇数の数
  int even, odd;
  even = K / 2;
  odd = (K+1) / 2;
  // 中学レベルの組み合わせ問題 Aから1つBから一つ取り出す時の場合の数は
  int out = even * odd;
  cout << out <<  endl;
  return 0;
}
