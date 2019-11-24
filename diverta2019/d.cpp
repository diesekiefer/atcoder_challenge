#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main(){
  long long  N;
  cin >> N;
  long long ans = 0;

  // N =  m * n + n を満たす m, n の組が存在するかどうか
  // N = n(m+1)
  // m > n > 0

  for (long long i=1; i * i < N; i++){
    // n = i,  m = N / i - 1
    if (N % i == 0 && N / i - 1 != i){
        ans += N / i - 1;
    }
  }

  cout << ans << endl;
  return 0;
}
