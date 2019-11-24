// 一番広い白の領域を探すだけでよい

#include <iostream>
#include <string>
using namespace std;

int find_white_space(int **board, int H, int W){
  // 四隅にだけ黒がある最大の正方形が n * n だった場合 その対角線の長さが必要な遷移回数になる
  int N = H < W? H: W;
  for (int n=N; n>0; n--){
    // n * n の正方形を探す
    for (int h=0; h<H-n+1; h++){
      for (int w=0; w<W-n+1; w++){
        // 左上が (h, w)の正方形が条件に合致するか調べる
        if (board[h][w] == 1 || board[h+n-1][w] == 1 || board[h][w+n-1] || board[h+n-1][w+n-1]){
          // 四隅のどこかが黒
          bool flag = true;
          for (int x=0; x<n; x++){
            if (!flag) break;
            for (int y=0; y<n; y++){
              // 正方形の中身
              if ((x == 0 && y == 0) || (x == n-1 && y == 0) || (x == 0 && y == n-1) || (x == n-1 && y == n-1)){
                // 四隅は無視
                continue;
              }
              if (board[h+x][w+y] == 1){
                // 正方形の中に黒がある
                flag = false;
                break;
              }
            }
          }
          if (flag){
            // 最大の正方形が見つかった
            return n;
          }
        }
      }
    }
  }
  // 全部黒だった
  return 0;
}

int main(){
  int H, W;
  cin >> H >> W;
  string A[H];
  for (int i=0; i<H; i++){
    cin >> A[i];
  }
  // 初期化
  int board[H][W];
  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      if (A[h][w] == '#'){
        board[h][w] = 1;
      } else{
        board[h][w] = 0;
      }
    }
  }

  int *tmp[H];
  for (int i=0; i<H; i++) tmp[i] = board[i];

  int output = find_white_space(tmp, H, W);

  cout << output << endl;
  return 0;
}
