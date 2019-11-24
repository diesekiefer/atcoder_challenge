// 黒をみて隣の白を黒に変える。変えるときに必要な手順数を一つ増やす。

#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int i=0; i<H; i++){
    cin >> A[i];
  }

  queue<tuple<int, int, int>> Q;
  vector<vector<int>> dists(H, vector<int>(W, 1000000));

  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      if (A[h][w] == '#'){
        Q.push(make_tuple(h, w, 0));
        dists[h][w] = 0;
      }
    }
  }

  while(!Q.empty()){
    int h, w, dist;
    tie(h, w, dist) = Q.front();
    Q.pop();
    if (dists[h][w] < dist) continue;
    static const array<int, 4> dh = {1, -1, 0, 0};
    static const array<int, 4> dw = {0, 0, 1, -1};
    for (int i=0; i<4; i++){
      const int nh = h + dh[i];
      const int nw = w + dw[i];
      const int ndist = dist + 1;
      if (nh >= 0 && nh < H && nw >= 0 && nw < W){
        if (chmin(dists[nh][nw], ndist)){
          Q.push(make_tuple(nh, nw, ndist));
        }
      }
    }
  }

  int ans = 0;
  for(int h=0; h<H; h++){
    for(int w=0; w<W; w++){
      chmax(ans, dists[h][w]);
    }
  }

  cout << ans << endl;
  return 0;
}
