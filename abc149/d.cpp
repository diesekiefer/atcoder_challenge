#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N, K, R, S, P;
    cin >> N >> K;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    vector<int> scores = {R, S, P};
    vector<int> Tlist(N);
    for (int i=0; i<N; i++){
        if (T[i] == 'r') Tlist[i] = 2; //グーに勝つのはパーなのでパーを出すことで score[2] 点が手に入る
        if (T[i] == 's') Tlist[i] = 0;
        if (T[i] == 'p') Tlist[i] = 1;
    }

    int ans=0;
    for (int i=0; i<K; i++){
        // i, i+K, i+2K, ... の列について考える
        // i+K と　i は同じ手を出してはいけないということは、どちらかでは負ける必要がある
        int j = i;
        int flag = 0;
        while(j < N){
            if (j < K){
                // 制約がないので勝てる
                // printf("%d\n", scores[Tlist[j]]);
                ans += scores[Tlist[j]];
            } else{
                if (T[j] == T[j - K] && flag == 0){
                    // printf("%c\n", T[j]);
                    flag = 1;
                } else{
                    // 前と同じ手を出せる
                    ans += scores[Tlist[j]];
                    // printf("%d\n", scores[Tlist[j]]);
                    flag = 0;
                }
            }
            j += K;
        }
    }

    cout << ans << endl;
    return 0;
}
