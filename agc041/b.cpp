#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, V, P;
ll M;

// 遅い
int solve(int i, vector<ll> &A){
    // A[i] が選ばれる可能性があるかどうか判定する
    // A[i] にM回投票されたときに上位に入る可能性があるかどうか
    // 各投票者が A[i] の他にもV-1 回投票することに注意する必要がある
    // A[i] のライバルになりえない（弱いやつ or (P-1)個まで上限の強いやつに投票する）
    // 総投票数は M * V でこれを各問Mを上限に任意の問題に分配可能
    // A[P-1] > A[j] + M だった場合何をやっても無理 
    // P-1 問の上位にV振る、A[i] に M 振る、A[i]より低いスコアの問題A[j]に M振る
    // A[P-1]からA[i-1]の問題のなかで、M + A[i] >= A[j] を満たす A[j] に M - A[j] + A[i] 振る
    // ここまでで　M * V 個振れたらok

    if (i == N) return 1;
    if (A[P-1] > A[i] + M) return 1;

    ll cnt = M * V;
    cnt -= (P - 1) * M;
    cnt -= M;
    cnt -= (N-i-1) * M;

    for (int j=P-1; j<i; j++){
        if (M + A[i] >= A[j]){
            cnt -= M - A[j] + A[i];
        }
    }
    if (cnt <= 0){
        return 0;
    }
    return 1;
}

int main(){
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), [](ll a, ll b){
        return a > b;
    });
    // for (ll a : A){
    //     cout << a << " ";
    // }
    // cout << endl;

    // 二分探索
    int l=0; // ぜったい通る
    int r=N; // 絶対通らない
    while(r-l > 1){
        int c = (l+r) / 2;
        if (solve(c, A) == 0){
            l = c;
        } else{
            r = c;
        }
    }
    cout << r << endl;

    return 0;
}
