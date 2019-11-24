#include<bits/stdc++.h>
using namespace std;

int main(){
  long long W, H, x, y;
  cin >> W >> H >> x >> y;

  // 長方形を均等に分割する方法は必ずあるはずなので、面積については半分の面積を返せば良い
  // (x, y) が長方形の中心の場合、分割する方法が複数存在するそれ以外で分割する方法が複数あるかどうか
  // if (W % 2 == 0 || H % 2 ==0){
  //   // 面積は整数
  //   long long ans = W * H / 2;
  //   if ((x == W / 2) && (y == H / 2)){
  //     printf("%lld %c", ans, '1');
  //     // cout << ans << " " << '1' << endl;
  //   } else{
  //     printf("%lld %c", ans, '0');
  //     // cout << ans << " " << '0' << endl;
  //   }
  // } else{
  //   long double ans = (long double)W * (long double)H / 2.0L;
  //   printf("%.1Lf %c", ans, '0');
  //   // cout << ans << " " << '0' << endl;
  // }
  printf("%lf %d", double(W)*double(H) / 2.0, x + x == W && y + y == H);
  return 0;
}
