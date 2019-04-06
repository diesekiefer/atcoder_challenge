// 入力は N 個の変数 にそれぞれ M 個の変数がついている
// これとは別に B_1, ... , B_M の変数がある
// 変数のBとの積の総和を評価してうんぬんする
// 変数は多くない

#include <iostream>
#include <string>
using namespace std;

int main(){
  int N, M, C;
  cin >> N >> M >> C;

  int A[N][M];
  int B[M];

  for (int i=0; i<M; i++){
    cin >> B[i];
  }

  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      cin >> A[i][j];
    }
  }

  int counter = 0;
  for (int i=0; i<N; i++){
    int tmp=0;
    for (int j=0; j<M; j++){
      tmp += A[i][j] * B[j];
    }
    if (tmp + C > 0){
      counter++;
    }
  }

  cout << counter << endl;
  return 0;
}
