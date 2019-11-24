#include<bits/stdc++.h>
using namespace std;

long long combination(long long n, long long r) {
  if ( r * 2 > n ) r = n - r;
  long long divided = 1;
  long long divisor  = 1;
  for (long long i = 1; i <= r; ++i ) {
    divided = divided * (n-i+1);
    divisor  = divisor * i;
  }
  return divided / divisor;
}


int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i=0; i<N; i++){
    cin >> S[i];
  }
  for (int i=0; i<N; i++){
    sort(S[i].begin(), S[i].end());
  }

  // vector<vector<int>> alph_cnt(N, vector<int>(26, 0));
  //
  // for (int i=0; i<N; i++){
  //   for (int j=0; j<10; j++){
  //     int k = S[i][j] - 'a';
  //     alph_cnt[i][k]++;
  //   }
  // }
  // int ans=0;
  // for (int i=0; i<N; i++){
  //   for (int j=i+1; j<N; j++){
  //     if (equal(alph_cnt[i].cbegin(), alph_cnt[i].cend(), alph_cnt[j].cbegin())){
  //       ans++;
  //     }
  //   }
  // }
  // int cnt = 1;
  // vector<string> s_list(N);
  // s_list[0] = S[0];
  // for (int i=1; i<N; i++){
  //   for (int j=0; j<cnt; j++){
  //     if (S[i] == s_list[j]){
  //       break;
  //     }
  //     s_list[cnt] = S[i];
  //     cnt++;
  //   }
  // }

  sort(S.begin(), S.end());
  // for (int i=0; i<N;i++){
  //   cout << S[i] << endl;
  // }
  int cnt = 1;
  vector<int> num(N, 1);
  // for (int i=0; i<N;i++){
  //   cout << num[i] << endl;
  // }
  for (int i=1; i<N; i++){
    if (S[i-1] == S[i]){
      num[cnt-1]++;
    } else{
      cnt++;
    }
  }
  // for (int i=0; i<cnt; i++){
  //   cout << num[i] << endl;
  // }
  // cout << endl;
  // cnt の数だけ異なるやつがあって、それぞれ num[cnt]個揃ってる
  // 組み合わせの数は num[cnt]_C_2
  long long ans = 0;
  for (int i=0; i<cnt; i++){
    if (num[i] != 1){
      ans += combination((long long)num[i], 2);
    }
  }
  cout << ans << endl;
  return 0;
}
