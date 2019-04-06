// 10の倍数縛り

#include <iostream>
#include <string>
using namespace std;

int main(){
  int A, B, C, D, E;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  cin >> E;

  // 最後に何を注文するかが大事
  // mod 10 を計算して最小のものが最後に届くようにする
  int last_menu = A;
  if ( (last_menu - 1) % 10 > (B - 1) % 10 ){
    last_menu = B;
  }
  if ( (last_menu - 1) % 10 > (C - 1) % 10 ){
    last_menu = C;
  }
  if ( (last_menu - 1) % 10 > (D - 1) % 10 ){
    last_menu = D;
  }
  if ( (last_menu - 1) % 10 > (E - 1) % 10 ){
    last_menu = E;
  }
  // cout << last_menu << endl;
  int totaltime = 0;
  totaltime += A + 9 - (A-1) % 10;
  totaltime += B + 9 - (B-1) % 10;
  totaltime += C + 9 - (C-1) % 10;
  totaltime += D + 9 - (D-1) % 10;
  totaltime += E + 9 - (E-1) % 10;
  totaltime -= 9 - (last_menu-1) % 10;
  cout << totaltime << endl;
  return 0;
}
