#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N, K;
  string S;
  cin >> S;

  for (int i=0; i<N; i++){
    if (i == K){
      cout << S[i] - 'A' + 'a';
    }
    cout << S[i];
  }
  cout << endl;
  return 0;
}
