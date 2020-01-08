#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, V, P;
ll M;

int main(){
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), [](ll a, ll b){
        return a > b;
    });

    // dp で解ける？
    // 要素:問題数、
    // 投票数が0のとき A の上から P 個が採用される
    // 投票数が1増えたとき、何を考慮するべきか？
    // 
    
    dp[N][V+1];
    for (int i=0; i<N; i++){
        for (int j=0; j<V; j++){
            dp[i][j] = 0;
        }
    }
    for (int i=0; i<P; i++){
        dp[i][0] = i;
    }
    for (int i=0; i<P; i++){
        for (int j=0; j<=V; j++){

        }
    }

    cout << dp[P-1][V] << endl;

    return 0;
}
