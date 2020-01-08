#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ll calc(ll A, ll B, ll N){
//     if (A < N - B - 1){
//         return A + (B - A) / 2 + 1;
//     } else{
//         return N - B - 1 + (B - A) / 2 + 1;
//     }
// }

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    A--;
    B--;
    ll dist = abs(A - B);
    ll ans = 0;
    if (dist % 2 == 0){
        ans = dist / 2; 
    } else{
        if (A < B){
            ll dist1 = min(A, N - B - 1);
            ans = dist1 + (dist + 1) / 2;
            // ll way1 = min(N - A - 1, B);
            // ll way2 = calc(A, B, N); 
            // ans = min(way1, way2);
        } else{
            ll dist1 = min(B, N - A - 1);
            ans = dist1 + (dist + 1) / 2;
            // ll way1 = min(N - B - 1, A);
            // ll way2 = calc(B, A, N);
            // ans = min(way1, way2);
        }
    }   
    cout << ans << endl;

    return 0;
}
