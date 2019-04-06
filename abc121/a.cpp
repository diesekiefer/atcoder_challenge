// H * W のマス目の h個の行と　w個の列を塗りつぶした時に残る白マスの数

#include <iostream>
#include <string>
using namespace std;

int main(){
  int H, W, h, w;
  cin >> H >> W;
  cin >> h >> w;

  // h個の行を塗りつぶすと h * W 個　消える
  // w個の列を塗りつぶすと w * H 個　消える
  // 重複する数は h * w なのでこれを補正する
  int output;
  output = H * W - h * W - w * H + h * w;
  cout << output << endl;
  return 0;
}
