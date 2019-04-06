// 橋渡し問題
// 結局は律速がどこにあるのかを考える必要がある

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int main(){
  long N, capacity[5];
  cin >> N;
  for (int i=0; i<5; i++){
    cin >> capacity[i];
  }
  // 最小値
  int min_capa_id = -1;
  long min_capa = LONG_MAX;
  for (int i=0; i<5; i++){
    if (capacity[i] < min_capa){
      min_capa = capacity[i];
      min_capa_id = i;
    }
  }

  long output = 5;
  // 律速のキャパで割る
  if (N % capacity[min_capa_id] == 0){
    output += N /capacity[min_capa_id] - 1;
  } else{
    output += N / capacity[min_capa_id];
  }
  cout << output << endl;
  return 0;
}
