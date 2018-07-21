#include <bits/stdc++.h>
using namespace std;

string flip(string s, int i){
  string out(s.length(), 'a');
  for (int j=0; j<s.length(); j++){
    int n = i + j;
    if (i + j >= s.length()){
      n = n - s.length();
    }
    out[j] = s[n];
  }
  return out;
}

int main() {
  string s, t;
  cin >> s;
  cin >> t;
  // cout << s.length() << endl;
  // cout << t << endl;

  for (int i=0; i<s.length(); i++){
    string new_s = flip(s, i);
    // cout << new_s << endl;
    if (new_s == t){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
