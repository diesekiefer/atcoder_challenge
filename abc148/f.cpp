#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G, vector<int> &dist, int p, int p=-1; int d=0){
    dist[p] = d;
    for (auto )
}

vector<int> calc_dist(vector<vector<int>> &G, int p){
    vector<int> dist(N);
    dfs(G, dist, p);
}

int main(){
    int N, u, v;
    cin >> N >> u >> v;
    vector<vector<int>> G(N);
    
    for (int i=0; i<N; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist_u = calc_dist(G, u);
    vector<int> dist_v = calc_dist(G, v);

    return 0;
}
