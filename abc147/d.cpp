#include<bits/stdc++.h>
using namespace std;

int LEN = 60;
int MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i=0; i<N; i++){
        cin >> a[i];
    }
    vector<vector<int>> cnt(LEN,vector<int>(2));

    for (int i=0; i<N; i++){
        for (int j=0; j<LEN; j++){
            cnt[j][a[i]>>j&1]++;
        }
    }

    int ans=0;
    for (int i=0; i<LEN; i++){
        ans += (1LL << i) % MOD * cnt[i][0] % MOD * cnt[i][1] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
  return 0;
}
