#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 0;
  if (N < 10){
    ans += N;
  } else{
    ans += 9;
    if (N < 100){
      ans += 0;
    } else if (N < 1000){
      ans += N - 99;
    } else{
      ans += 900;
      if (N < 10000){
        ans += 0;
      } else if (N < 100000){
        ans += N - 9999;
      } else{
        ans += 90000;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
