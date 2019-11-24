#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  // A = 2K - B
  // A < K < B
  // K = (A + B) / 2
  if ((A + B) % 2 == 0){
    int K = (A + B) / 2;
    cout << K << endl;
  } else{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
