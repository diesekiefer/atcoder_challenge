#include<bits/stdc++.h>
using namespace std;

bool cmp(const tuple<int, string, int>& x, const tuple<int, string, int>& y){
  if (get<1>(x) == get<1>(y)){
    return get<2>(x) > get<2>(y);
  } else{
    if (get<1>(x).compare(get<1>(y)) < 0){
      return true;
    } else{
      return false;
    }
  }
}

int main(){
  int N;
  cin >> N;
  vector<tuple<int, string, int>> vec;

  for (int i=0; i<N; i++){
    string s;
    int p;
    cin >> s >> p;
    vec.emplace_back(i+1, s, p);
  }

  sort(
    vec.begin(),
    vec.end(),
    cmp
  );

  for (int i=0; i<N; i++){
    cout << get<0>(vec[i]) << endl;
  }
  return 0;
}
