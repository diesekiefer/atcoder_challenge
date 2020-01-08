#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A, B, K;
    cin >> A >> B >> K;

    if (A + B < K){
        cout << 0  << " " << 0 << endl;
    } else{
        if (A < K){
            cout << 0 << " " << B - (K - A) << endl;
        } else{
            cout << A - K << " " << B << endl;
        }
    }
    return 0;
}
