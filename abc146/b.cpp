#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;

  for (int i=0; i<S.length(); i++){
    S[i] += N;
    if ('Z' < S[i]){
      S[i] -= 26;
    }
  }
  cout << S << endl;
  return 0;
}
