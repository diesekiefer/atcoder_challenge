#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int count_AB(string s, int l){
  int ans = 0;
  for (int i=0; i<l-1; i++){
    if (s[i] == 'A' && s[i+1] == 'B'){
      ans++;
      i++;
    }
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  int ans = 0;
  int start_B = 0;
  int end_A = 0;
  int both = 0;
  for (int i=0; i<N; i++){
    cin >> S[i];
    int l = S[i].length();
    // S[i] に AB が含まれる個数を数えて足し合わせていく
    ans += count_AB(S[i], l);
    // Bで始まるやつとAで終わるやつとその両方のやつをそれぞれ数える
    if (S[i][0] == 'B'){
      start_B++;
    }
    if (S[i][l-1] == 'A'){
      end_A++;
    }
    if (S[i][0] == 'B' && S[i][l-1] == 'A'){
      both++;
    }
  }

  //　並び替えで ABが生まれうるのはB で始まるやつとAで終わるやつが存在するとき
  if (start_B == end_A){
    if (both == start_B){
      if (start_B != 0){
        ans += start_B - 1;
      }
    } else{
      ans += start_B;
    }
  } else{
    chmin(start_B, end_A);
    ans += start_B;
  }
  cout << ans << endl;
  return 0;
}
