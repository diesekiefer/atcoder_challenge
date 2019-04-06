#include <bits/stdc++.h>
using namespace std;

int main() {
  int D;
  long G;
  cin >> D;
  cin >> G;
  vector<int> p(D);
  vector<long> c(D);
  for (int i=0; i<D; i++){
    cin >> p.at(i);
    cin >> c.at(i);
  }

  // G を達成するための最小数を考える
  // まず，コンプリートボーナスを考慮しない場合 -> 配点の大きい問題から解くべき -> しかしコンプリートボーナスは発生するので完全に分けて考えることは難しい
  // コンプリートボーナスを得るかどうかを全探索する -> その上で最小数を探る　こうすれば大きい問題から解いて行くことが可能
  // 2^D通りの全探索か
  long min_num = 1000;

  for (int i=0; i<pow(2, D); i++){
    // i を2進数にするといい感じになるか
    
  }


  long score = G;
  int solved_num = 0;
  cur_id = D;
  while (score > 0){
    if (score >= 100*cur_id*c.at(cur_id-1)){
      solved_num += c.at(cur_id-1);
      score -= 100*cur_id*c.at(cur_id-1);
    } else{
      solved_num += G / (100*cur_id);
      score = G % (100*cur_id);
    }
    cur_id -= 1;
  }



  int len = S.size();
  if (S.at(0) != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  if (S.at(1) >= 'A' && S.at(1) <= 'Z'){
    cout << "WA" << endl;
    return 0;
  }
  bool flag = true;
  for (int i=2; i<len-1; i++){
    if (S.at(i) == 'C'){
      if (flag){
        flag = false;
      } else{
        cout << "WA" << endl;
        return 0;
      }
    } else{
      if (S.at(i) >= 'A' && S.at(i) <= 'Z'){
        cout << "WA" << endl;
        return 0;
      }
    }
  }
  if (flag){
    cout << "WA" << endl;
    return 0;
  }
  if (S.at(len-1) >= 'A' && S.at(len-1) <= 'Z'){
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}
