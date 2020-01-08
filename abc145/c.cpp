#include<bits/stdc++.h>
using namespace std;

// double solve(double ans, int here, vector<int> dest, int N, vector<vector<double>> dist){
//     // printf("N: %d\n", N);
//     // for (int i=0; i<N; i++){
//     //   printf("%d, ", dest[i]);
//     // }
//     // printf("\n");
//     double tmp = 0;
//     for (int i=0; i<N; i++){
//         // here から dest.at(i) への距離
//         double d = 0;
//         if (here >= 0){
//             d = dist.at(here).at(dest.at(i));
//         }
//         vector<int> new_dest;
//         for (int j=0; j<N; j++){
//             if (i==j) continue;
//             new_dest.push_back(dest.at(j));
//         }
//         tmp += ((N-1) * d + solve(ans, dest.at(i), new_dest, N-1, dist));
//     }
//     return (ans + tmp);
// }

double distance(vector<int> p1, vector<int> p2){
    return sqrt((p2.at(0) - p1.at(0)) * (p2.at(0) - p1.at(0)) + (p2.at(1) - p1.at(1)) * (p2.at(1) - p1.at(1)));
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> point(N, vector<int> (2));
    for (int i=0; i<N; i++){
        cin >> point.at(i).at(0) >> point.at(i).at(1);
    }
    
    vector<vector<double>> dist(N, vector<double> (N));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i==j){
                dist.at(i).at(j) = 0;
            } else{
                dist.at(i).at(j) = distance(point.at(i), point.at(j));
            }
            //cout << dist.at(i).at(j) << endl;
        }
    }
    
    double ans = 0;
    // vector<int> dest(N);
    // for (int i=0; i<N; i++){
    //     dest.at(i) = i;
    // }
  	// ans = solve(ans, -1, dest, N, dist);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            ans += dist.at(i).at(j);
        }
    }
    // (N - 1) / (N * N - N) = 1 / N
    // int cnt = 1;
    // for (int i=0; i<N; i++){
    //   cnt *= i+1;
    // }
    
    printf("%.10f\n", ans / N);
    return 0;
}
