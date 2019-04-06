#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;

  // ベクトルを計算する
  int dx = x2 - x1;
  int dy = y2 - y1;

  // 三つめの点はベクトルを 2/pi 回転させたものなので
  x3 = x2 - dy;
  y3 = y2 + dx;

  // 四つめの点はベクトルを pi 回転させたものなので
  x4 = x3 - dx;
  y4 = y3 - dy;

  cout << x3 << " " << y3 << " " << x4 << " " << y4 <<  endl;
  return 0;
}
