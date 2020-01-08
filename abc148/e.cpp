#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    if (N % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    
    // vector<ll> fives(N);
    // for (ll i=0; i<N; i++){
    //     fives[i] = 0;
    // }
    ll ans = 0;
    ll m = 5;
    while(m <= N){
        for (ll i=2; i < (N / m + 1); i+=2){
            if (i * m % 2 == 0){
                ans += 1;
            }
        }
        m *= 5;
    }

    // for (ll i=0; i<N/2; i++){
    //     while(arr[i] % 5 == 0){
    //         ans += 1;
    //         arr[i] /= 5;
    //     }
    // }
    // ll ans = 0;
    // for (ll i=0; i<N/2; i++){
    //     ans += fives[i*2];
    // }
    cout << ans << endl;
    return 0;
}
