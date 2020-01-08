#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i=0; i<N; i++){
        cin >> a[i];
    }
    int ans = 0;
    int c = 0;
    for (int i=0; i<N; i++){
        if (a[i] == c+1){
            c++;
        } else{
            ans++;
        }
    }
    if (ans == N){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }
    return 0;
}
