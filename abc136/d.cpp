#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N = S.length();

  // R が並んでいたら右に行く Lが並んでいたら左に行く
  // 止まるのはRLの境界のみ。それ以外は0
  // 偶数回移動するので、境界から奇数番目はRに、偶数番目はLに入る

  // 境界の数だけ配列を作り、そのidxとLRの数を保存したい
  char tmp = S[0];
  int cnt = 0;
  for (int i=0; i<N; i++){
    if (tmp != S[i]){
      cnt++;
    }
    tmp = S[i];
  }
  int seg_num = (cnt+1) / 2;

  vector<int> R(seg_num); // そのセグメントのRの数
  vector<int> L(seg_num); // そのセグメントのLの数
  vector<int> idx(seg_num); // そのセグメントの境界（Rの方）の位置

  cnt = 0;
  int r_cnt = 0;
  int l_cnt = 0;
  int flag = 0; // 0: R, 1: L
  int seg_idx = 0;
  for (int i=0; i<N; i++){
    //左から見ていく
    if (flag == 0){
      if (S[i] == 'R'){
        r_cnt++;
      } else{
        // R L の境界
        R[seg_idx] = r_cnt;
        idx[seg_idx] = i-1;
        l_cnt = 1;
        flag = 1;
      }
    } else{
      if (S[i] == 'R'){
        // L R の境界
        L[seg_idx] = l_cnt;
        seg_idx++;
        r_cnt = 1;
        flag = 0;
      } else{
        l_cnt++;
      }
    }
  }

  L[seg_idx] = l_cnt;


  vector<int> Masu(N);
  for (int i=0; i<N; i++){
    Masu[i] = 0;
  }

  for (int i=0; i<seg_num; i++){
    // 偶数の時は半々で分ける
    // 奇数の時は、Rの場合はRにひとつ多く Lの時はLにひとつおおく入る
    if (R[i] % 2 ==0){
      Masu[idx[i]] += R[i] / 2;
      Masu[idx[i]+1] += R[i] / 2;
    } else{
      Masu[idx[i]] += R[i] / 2 + 1;
      Masu[idx[i]+1] += R[i] / 2;
    }
    if (L[i] % 2 == 0){
      Masu[idx[i]] += L[i] / 2;
      Masu[idx[i]+1] += L[i] / 2;
    } else{
      Masu[idx[i]] += L[i] / 2;
      Masu[idx[i]+1] += L[i] / 2 + 1;
    }
  }

  for (int i=0; i<N; i++){
    cout << Masu[i] << " ";
  }
  cout << endl;
  return 0;
}
