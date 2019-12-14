#include<bits/stdc++.h>
using namespace std;

// 回答リストを用意しておいて、それとマッチするかどうかを判定する関数を書く。
// 回答リストの数はたかだか2*15 なので多分実時間実行可能

int count_num(vector<int> v, int N){
  int ans = 0;
  for (int i=0; i<N; i++){
    if (v[i] == 1){
      ans++;
    }
  }
  return ans;
}

vector<int> create_v(int n, int N){
  vector<int> v(N);
  for (int i=0; i<N; i++){
    v[i] = n % 2;
    n /= 2;
  }
  return v;
}

int solve(vector<vector<int>> vv, vector<int> v, int N){
  for (int i=0; i<N; i++){
    // 不親切な人の話は聞かない
    if (v[i] == 0) continue;
    for (int j=0; j<N; j++){
      if (vv[i][j] != 2){
        // printf("x:%d, y:%d\n", vv[i][j], v[j]);
        if (vv[i][j] != v[j]){
          // 矛盾している
          return 1;
        }
      }
    }
  }
  return 0;
}

int main(){
  int N;
  cin >> N;
  vector<int> num_test(N, 0);
  vector<vector<int>> table(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      table.at(i).at(j) = 2;
    }
  }

  // ある人に対してどのような証言がなされているかをリストとして集める

  for (int i=0; i<N; i++){
    cin >> num_test[i];
    for (int j=0; j<num_test[i]; j++){
      int x, y;
      cin >> x >> y;
      table[i][x-1] = y;
    }
  }

  // for (int i=0; i<N; i++){
  //   for (int j=0; j<N; j++){
  //     printf("%d ", table[i][j]);
  //   }
  //   printf("\n");
  // }

  int max = 0;
  for (int i=0; i<(int)pow(2, N); i++){
    vector<int> v = create_v(i, N);
    // printf("%d %d %d\n", v[0], v[1], v[2]);
    // printf("solve: %d\n", solve(table, v, N));
    if (solve(table, v, N) == 0){
      int tmp = count_num(v, N);
      // printf("%d\n", tmp);
      if (max < tmp){
        max = tmp;
      }
    }
  }
  cout << max << endl;
  return 0;
}
