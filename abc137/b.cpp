#include<bits/stdc++.h>
using namespace std;

int main(){
  int K, X;
  cin >> K >> X;

  int max_idx = 0;
  if (X + K - 1 >= 1000000){
    max_idx = 1000000;
  } else{
    max_idx = X + K - 1;
  }

  int min_idx = 0;
  if (X - K + 1 <= -1000000){
    min_idx = -1000000;
  } else{
    min_idx = X - K + 1;
  }

  for (int i = min_idx; i<= max_idx; i++){
    cout << i << " ";
  }
  cout << endl;
}
