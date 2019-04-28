#include <iostream>
#include <string>
using namespace std;

int main(){
  string S;
  cin >> S;

  int l = (int)S.length();

  int out = 0;
  int color = S[0] - '0';

  for (int i=1; i<l; i++){
    // 交互になるようにすれば良い
    // next_color = 1 - color
    // cout << S[i] << color << endl;
    if (S[i] - '0' == color){
      out += 1;
    }
    color = 1 - color;
  }

  cout << out << endl;
  return 0;
}
