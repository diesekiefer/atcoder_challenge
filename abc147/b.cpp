#include<bits/stdc++.h>
using namespace std;


int solve(string s1, string s2){
  int ans = 0;
  for (int i=0; i<s1.length(); i++){
    if (s1[i] != s2[s2.length() - 1 - i]){
      ans++;
    }
  }
  return ans;
}

int main(){
  string S;
  cin >> S;

  int l = S.length();

  if (l % 2 == 0){
    cout << solve(S.substr(0, l / 2), S.substr(l / 2, l / 2)) << endl;
  } else{
    cout << solve(S.substr(0, (l-1) / 2), S.substr((l+1) / 2, (l-1) / 2)) << endl;
  }
  return 0;
}
