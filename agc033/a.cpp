// これは実行時間が遅すぎる。改良アルゴリズムを思いついた

#include <iostream>
#include <string>
using namespace std;

// void print_board(int **board, int H, int W){
//   for (int h=0; h<H; h++){
//     for (int w=0; w<W; w++){
//       if (board[h][w] == 1){
//         cout << '#';
//       } else{
//         cout << '.';
//       }
//     }
//     cout << endl;
//   }
// }

int update_board(int **board, int H, int W){
  int next_board[H][W];
  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      next_board[h][w] = board[h][w];
    }
  }

  int num_black = 0;
  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      if (board[h][w] == 1){
        num_black += 1;
        if (h != 0) next_board[h-1][w] = 1;
        if (h != H-1) next_board[h+1][w] = 1;
        if (w != 0) next_board[h][w-1] = 1;
        if (w != W-1) next_board[h][w+1] = 1;
      }
    }
  }

  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      board[h][w] = next_board[h][w];
    }
  }

  return num_black;
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
  // int num_black = 0;
  for (int h=0; h<H; h++){
    for (int w=0; w<W; w++){
      if (A[h][w] == '#'){
        board[h][w] = 1;
        // num_black += 1;
      } else{
        board[h][w] = 0;
      }
    }
  }

  // 全部黒だった時の対処
  // if (num_black == H * W){
  //   cout << 0 << endl;
  //   return 0;
  // }

  int *tmp[H];
  for (int i=0; i<H; i++) tmp[i] = board[i];
  int cnt = 0;
  while(true){
    if (update_board(tmp, H, W) == H * W){
      break;
    }
    cnt += 1;
    // print_board(tmp, H, W);
  }


  cout << cnt << endl;
  return 0;
}
