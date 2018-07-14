#include <bits/stdc++.h>
using namespace std;

vector<vector<long>> input(int N) {
  vector<vector<long>> vv;
  vv = vector<vector<long>>(N, vector<long>(4, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++){
      cin >> vv[i][j];
    }
  }
  return vv;
}

void output(string a) {
  cout << a << endl;
}

void rng(vector<vector<long>> vv, int N){
  // 在庫確認時に追加行動に移る個数が買う数よりも大きい場合は在庫が切れることはない．
  // しかし，確認するときの個数が小さくても問題ない場合がある.それは決まった数だけ買われるので追加する数がちょうど買われる数の定数倍である時，一回をクリアすれば良いことになる．
  int output = 0;
  int count = 0;
  int cur_color = -1;
  int flag = 0;

  for (int i=0; i<N; i++){
    long A = vv[i][0];
    long B = vv[i][1];
    long C = vv[i][2];
    long D = vv[i][3];

    // 当たり前や
    if (A < B){
      cout << "No" << endl;
      continue;
    }
    if (B <= C){
      cout << "Yes" << endl;
      continue;
    }
    long amari = A % B;

    // この時点でのあまりと，追加数個数と買う数の関係で決まります
    // amari + D が B で割り切れる場合 ok
    // 割り切れない場合 ... 次が行けるかどうかはどう決まるか？

    if ((amari + D) % B == 0){
      cout << "Yes" << endl;
      continue;
    }
    int cnt = 100;
    int flag = 0;
    long aa = amari;
    while (cnt > 0){
      aa = (aa + D) % B;
      // cout << aa << endl;
      if (aa > C){
        cout << "No" << endl;
        flag = 1;
        break;
      }
      cnt--;
    }
    if (flag == 0){
      cout << "Yes" << endl;
      continue;
    }
  }
  return;
}

int main() {
  int N;
  cin >> N;
  vector<vector<long>> A;
  A = input(N);
  rng(A, N);
}
