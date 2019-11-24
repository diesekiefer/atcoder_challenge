#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long modpow(long long a, long long n){
  long long res = 1;
  while (n > 0){
    if (n & 1){
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long modinv(long long a){
  return  modpow(a, mod-2);
}

long long modgamma(long long n){
  if (n < 0){
    return 0;
  }
  long long res = 1;
  for (long long i=0; i<n; i++){
    res = res * (i+1) % mod;
  }
  return res;
}

int main(){
  long long N, K;
  cin >> N >> K;

  // 並び替えの問題
  // 青いボールのグループの個数がiになる並べ方がいくつあるのかを計算する。
  // まず青いボールを i個のグループに分ける場合の数が何通りかを計算する
  // これは K-1個の境界からi-1個を選ぶ組み合わせの問題なので K-1_C_i-1
  // 次に赤いボールが並んだところに青いグループをどのように挿入するかの組み合わせの数を計算する
  // これは N - K + 1個の境界（両端含む）からi個を選ぶ組み合わせの問題なので N-K+1_C_i

  for (long long i=1; i<=K; i++){
    long long ans = modgamma(K-1) * modinv(modgamma(i-1)) % mod;
    ans = ans * modinv(modgamma(K-i)) % mod;
    ans = ans * modgamma(N-K+1) % mod;
    ans = ans * modinv(modgamma(i)) % mod;
    ans = ans * modinv(modgamma(N-K+1-i)) % mod;
    cout << ans << endl;
  }
  return 0;
}
