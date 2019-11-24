#include<bits/stdc++.h>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> pairs(N);
  for (int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    pairs[i] = make_pair(a, b);
  }
  sort(pairs.begin(), pairs.end(), compare_by_b);
  // 多分　締め切りが一番近いかつからやるといいと思う
  int time = 0;
  for (int i=0; i<N; i++){
    // printf("%d\t%d\n", pairs[i].first, pairs[i].second);
    time += pairs[i].first;
    if (time > pairs[i].second){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
