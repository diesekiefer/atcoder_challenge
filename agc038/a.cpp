#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  vector<vector <int>> Board(H, vector<int>(W, 0));
  // まず横を考えると、11100000的な奴をスライドさせて行って全体を作る必要がある
  // そのときに、縦が条件通りになっていればよい
  // スライドの範囲は 1 <= shift < H

  for (int shift=1; shift<H; shift++){
    for (int i=1; i<=H; i++){
      for (int j=1; j<=W; j++){
        if ((i + j*shift) % H <= A){
          Board[i-1][j-1] = 1;
        } else{
          Board[i-1][j-1] = 0;
        }
      }
    }
    for (int j=1; j<=W; j++){
      int sum = 0;
      for (int i=1; i<=H; i++){
        sum += Board[i-1][j-1];
      }
      if (2 * sum > W){
        sum = W - sum;
      }
      if (sum == B){
        for (int i=0; i<H; i++){
          for (int j=0; j<W; j++){
            cout << Board[i][j];
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
