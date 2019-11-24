#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i=0; i<N; i++){
    cin >> p[i];
  }
  // 昇順って綺麗に並んでるってことなので
  int flag = 0;
  for (int i=0; i<N; i++){
    if (p[i] != i+1){
      if (flag == 0){
        if (p[p[i]-1] != i+1){
          cout << "NO" << endl;
          return 0;
        } else{
          flag = i + 1;
        }
      } else{
        if (flag != p[i]){
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
