// N回の操作で数列 b_1, ... b_N を作れるかどうかを判定

// b_N が作成可能かどうかは b_{N-1}を見ればわかるか？
// b_{N}から n 番目のノードを除去したやつ　b_{N-1}[n]

// b_{n} が成立可能なのは
// b_{n}[1] = 1  かつ b_{n}[2..n] が成立可能な場合
// b_{n}[2] = 2 かつ b_{n}[1, 3..n] が成立可能な場合
// 以下同様


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int* pop(int *a, int N, int j){
  // N個の数列 a から j番目のものを除去する
  int copy[N];
  for (int i=1; i<=N; i++){
    copy[i] = a[i];
  }
  for (int i=j; i<N; i++){
    a[i] = copy[i+1];
  }
  return a;
}

string search(int *b, int N){
  // cout << b[1] <<  N << endl;
  if (N == 1){
    if (b[1] == 1){
      return "1";
    }
    else{
      return "0";
    }
  }
  for (int j=1; j<=N; j++){
    int tmp_b[N];
    for (int k=1; k<=N; k++){
      tmp_b[k] = b[k];
    }
    if (b[j] == j){
      // 可能性がある
      int *new_b  = pop(tmp_b, N, j);
      string tmp = search(new_b, N-1);
      if (tmp != "0"){
        return std::to_string(j) + tmp;
      }
    }
  }
  return "0";
}


int main(){
  int N;
  cin >> N;
  int b[N+1];
  for (int i=1; i<=N; i++){
    cin >> b[i];
  }

  // N * N の二次元配列 a[i][j] ... 数値が入ってる
  // a[i][j] == 1 i個の数列の頭からj番目にjを挿入したとき b_1 ...b_i が存在する
  int a[N+1][N+1];
  // 初期化
  for (int i=0; i<=N; i++){
    for (int j=0; j<=N; j++){
      a[i][j] = 0;
    }
  }

  // 答えを保存しておく

  // 再帰関数で書く
  string c = search(b, N);
  if (c == "0"){
    cout << "-1" << endl;
  } else{
    for (int i=0; i<N; i++){
      cout << c[i] << endl;
    }
  }
  return 0;
}
