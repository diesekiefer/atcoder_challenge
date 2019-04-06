// 入力 A_N
// A_i が 何回 2で割れるかを計算し最小の数を返す

#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  for (int i=0; i<N; i++){
    cin >> A[i];
  }

  int count = 0;
  while(true){
    bool flag = false;
    for (int i=0; i<N; i++){
      if (A[i] % 2 == 0){
        A[i] /= 2;
      } else{
        flag = true;
      }
    }
    if (flag){
      break;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
