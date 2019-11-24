#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  if (A - B > C){
    cout << 0 << endl;
  } else{
    cout << C - A + B << endl;
  }
  return 0;
}
