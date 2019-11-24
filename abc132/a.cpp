#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  char a = S[0];
  if (S[1] == a){
    if ((S[2] == S[3]) && (S[2] != a)){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  } else if (S[2] == a){
    if ((S[1] == S[3]) && (S[1] != a)){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  } else if (S[3] == a){
    if ((S[1] == S[2]) && (S[1] != a)){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  } else{
    cout << "No" << endl;
  }
  return 0;
}
