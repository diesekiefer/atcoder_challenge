#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int len = S.size();
  if (S.at(0) != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  if (S.at(1) >= 'A' && S.at(1) <= 'Z'){
    cout << "WA" << endl;
    return 0;
  }
  bool flag = true;
  for (int i=2; i<len-1; i++){
    if (S.at(i) == 'C'){
      if (flag){
        flag = false;
      } else{
        cout << "WA" << endl;
        return 0;
      }
    } else{
      if (S.at(i) >= 'A' && S.at(i) <= 'Z'){
        cout << "WA" << endl;
        return 0;
      }
    }
  }
  if (flag){
    cout << "WA" << endl;
    return 0;
  }
  if (S.at(len-1) >= 'A' && S.at(len-1) <= 'Z'){
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}
