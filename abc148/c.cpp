#include<bits/stdc++.h>
using namespace std;

long long GCD(long long m, long long n){
    long long tmp;
    while (m % n != 0){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

long long LCM(long long A, long long B){
    long long ans;
    if (A < B){
        ans = A * B / GCD(B, A);
    } else{
        ans = A * B / GCD(A, B);
    }
    return ans;
}

int main(){
    long long A, B;
    cin >> A >> B;

    long long ans = 0;
    ans = LCM(A, B);

    cout << ans << endl;
    return 0;
}
