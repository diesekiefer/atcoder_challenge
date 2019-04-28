#include <iostream>
#include <string>
using namespace std;

int main(){
  int N, K;
  cin >> N;
  cin >> K;
  string S;
  cin >> S;

  for (int k=0; k < K; k++){
    // 最も長い3グループを見つける
    int start = 0;
    int end = 0;
    int state = S[0] - '0';
    int length = 0;
    int group_3_length = 0;
    int groups[3];
    int group_idx[3];
    for (int i=1; i<3; i++){
      groups[i] = 0;
      group_idx[i] = 0;
    }

    for (int i=1; i<N; i++){
      if (S[i] - '0' != state){
        groups[2] = groups[1];
        groups[1] = groups[0];
        groups[0] = length;
        group_idx[2] = group_idx[1];
        group_idx[1] = group_idx[0];
        group_idx[0] = i;

        if (group_3_length < groups[0] + groups[1] + groups[2]){
          group_3_length += groups[0] + groups[1] + groups[2];
          start = group_idx[1];
          end = group_idx[0] - 1;
        }

        length = 0;
        state = 1 - state;
      }
      length += 1;
    }
    groups[2] = groups[1];
    groups[1] = groups[0];
    groups[0] = length;
    group_idx[2] = group_idx[1];
    group_idx[1] = group_idx[0];
    group_idx[0] = N-1;

    if (group_3_length < groups[0] + groups[1] + groups[2]){
      group_3_length += groups[0] + groups[1] + groups[2];
      start = group_idx[1];
      end = group_idx[0] - 1;
    }

    // 入れ替える
    cout << start << " " << end << endl;
    for (int i=start; i<=end; i++){
      S[i] = 1 - (S[i] - '0') + '0';
    }
  }
  cout << S << endl;

  // 最も長い１の列の個数
  int out = 0;
  int count = 0;
  for (int i=0; i<N; i++){
    if (S[i] == '1'){
      count += 1;
    } else{
      if (out < count){
        out = count;
      }
      count = 0;
    }
  }
  if (out < count){
    out = count;
  }

  cout << out << endl;
  return 0;
}
