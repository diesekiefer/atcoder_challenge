#include <bits/stdc++.h>
using namespace std;

vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int gcd(int x, int y)
{
    int r;

    if(x == 0 || y == 0)  // 引数チェック
    {
        fprintf(stderr, "引数エラーです。\n");
        return 0;
    }

    // ユーグリッドの互除法
    while((r = x % y) != 0) // yで割り切れるまでループ
    {
        x = y;
        y = r;
    }
    return y;
}

// 最大公約数を求める関数
int lcm(int x, int y)
{
    if(x == 0 || y == 0)  // 引数チェック
    {
        fprintf(stderr, "引数エラーです。\n");
        return 0;
    }

    return (x * y / gcd(x, y));
}

int mod(vector<int> A, int N, int max){
  long mmax = -1;
  for (int i=0; i<max; i++){
    long sum = 0;
    for (int j=0; j<N; j++){
      sum += i % A[j];
    }
    if (mmax < sum){
      // cout << sum << endl;
      mmax = sum;
    }
  }
  return mmax;
}

int main() {
  int N;
  cin >> N;
  vector<int> A;
  A = input(N);
  long max = 1;
  for (int i=0; i<N; i++){
    max = lcm(max, A[i]);
  }
  // cout << max << endl;
  cout << mod(A, N, max) << endl;
}
