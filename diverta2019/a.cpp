#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main(){
  int N, K;
  cin >> N >> K;

  int ans = N - K + 1;
  cout << ans << endl;
  return 0;
}
