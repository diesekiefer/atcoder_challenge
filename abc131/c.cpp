#include<bits/stdc++.h>
using namespace std;

long long gcd(long long m, long long n){
  long long tmp;
  while(m % n != 0){
    tmp = n;
    n = m % n;
    m = tmp;
  }
  return n;
}

int main(){
  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  long long min_c = ((A-1) / C) + 1;
  long long max_c = B / C;
  long long min_d = ((A-1) / D) + 1;
  long long max_d = B / D;

  // A と B の間の Cの倍数の個数は max_c - min_c + 1
  // A と B の間の Dの倍数の個数は max_d - min_d + !

  // A と B の間の CとD共通の倍数の個数は？
  // CとD最小公倍数を求める
  long long lcm = 0;
  if (C < D){
    lcm = C * D / gcd(D, C);
  } else{
    lcm = C * D / gcd(C, D);
  }
  long long min_lcm = ((A-1) / lcm) + 1;
  long long max_lcm = B / lcm;

  long long ans = B - A + 1 - (max_c - min_c + 1) - (max_d - min_d + 1) + (max_lcm - min_lcm + 1);
  cout << ans << endl;
  return 0;
}
