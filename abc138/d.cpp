#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;

  pair<int, int> Pair;
  vector<Pair> AB(N-1);
  for (int i=0; i<N-1; i++){
    cin >> AB.first >> AB.second;
  }
  // 各ノードの値
  vector<int> tree(N, 0);
  // 木構造を作りたい
    for (int i=0; i<N-1; i++){
      if (AB.first == 1){

      }
    }
  }

  vector<Pair> PX(Q);
  for (int i=0; i<Q; i++){
    cin >> PX.first >> PX.second;
  }

  vector<int> tree(N, 0);

  return 0;
}
