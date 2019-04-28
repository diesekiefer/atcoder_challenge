#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  // 左側に白 右側に黒が並ぶようにする

  // 最初に境界を調べる。
  int left_count[N+1]; // 左から見ていって#がある数
  int right_count[N+1]; // 右から見ていって.が出現した数
  for (int i=0; i<N+1; i++){
    left_count[i] = 0;
    right_count[i];
  }
  int l_cnt = 0;
  int r_cnt = 0;
  for (int i=0; i<N+1; i++){
    if (i == 0){
      left_count[i] = 0;
    } else{
      if (S[i-1] == '#'){
        l_cnt += 1;
      }
      left_count[i] = l_cnt;
    }

    if (i == 0){
      right_count[N-i] = 0;
    } else{
      if (S[N-i] == '.'){
        r_cnt += 1;
      }
      right_count[N-i] = r_cnt;
    }
  }
  // 境界は left_count と right_count の和が最小になるところ？
  int min = N;
  for (int i=0; i<N+1; i++){
    if (min > left_count[i] + right_count[i]){
      min = left_count[i] + right_count[i];
    }
  }
  cout << min << endl;

  // int out = 0;
  // int flag = 1;
  // int left_idx = 0;
  // int right_idx = N-1;
  // while(1){
  //   if (left_idx == right_idx){
  //     break;
  //   }
  //   if (flag){
  //     if (S[left_idx] == '#'){
  //       out += 1;
  //       flag = 0;
  //     }
  //     left_idx += 1;
  //   } else{
  //     if (S[right_idx] == '.'){
  //       out += 1;
  //       flag = 1;
  //     }
  //     right_idx -= 1;
  //   }
  // }
  return 0;
}
