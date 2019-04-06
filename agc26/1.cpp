#include <bits/stdc++.h>
using namespace std;

vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

void output(int a) {
  cout << a << endl;
}

int slime(vector<int> A, int N){
  // A のうち同じ数が隣り合っているものを見つける
  // もし隣り合っているものが奇数の場合，両端はそのままで間の色を変更するだけで良いので (n - 1)/2の回数で済む
  // もし隣り合っているものが偶数の場合，両端どちらかの色を変えて残りは交互に変化させればよいので n/2回か
  // 22112211 のような並びになっている場合，2313231
  int output = 0;
  int count = 0;
  int cur_color = -1;
  int flag = 0;

  for (int i=0; i<N; i++){
    if (flag == 1){
      if (A[i] == cur_color){
        // 引き続きやね
        count += 1;
      } else{
        // ここでおしまいということや
        if (count % 2 == 0){
          output += count / 2;
        } else{
          output += (count - 1) / 2;
        }
        count = 0;
        flag = 0;
      }
    } else {
      if (A[i] != cur_color){
        // なにもなし
      } else{
        // 出力待機モードにはいる
        count += 2;
        flag = 1;
      }
    }
    cur_color = A[i];
    // 最後の処理だけ
    if (i == N-1){
      if (count % 2 == 0){
        output += count / 2;
      } else{
        output += (count - 1) / 2;
      }
    }
  }
  return output;
}

int main() {
  int N;
  cin >> N;
  vector<int> A;
  A = input(N);
  output(slime(A, N));
}
