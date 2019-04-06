#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  long A[X], B[Y], C[Z];
  for (int i=0; i<X; i++){
    cin >> A[i];
  }
  for (int i=0; i<Y; i++){
    cin >> B[i];
  }
  for (int i=0; i<Z; i++){
    cin >> C[i];
  }

  sort(A, A + X, greater<long>());
  sort(B, B + Y, greater<long>());
  sort(C, C + Z, greater<long>());

  int max_K = min(3000, X * Y * Z);
  long output[max_K];
  for (int i=0; i<max_K; i++){
    output[i] = 0;
  }
  int count = 0;
  int x=0;
  int y=0;
  int z=0;
  while(count < max_K){
    // 価値を入れていく
    output[count] = A[x] + B[y] + C[z];
    // cout << output[count] << endl;
    count++;

    // x, y, z を更新
    long next_A, next_B, next_C;
    if (x == X-1){
      next_A = -1;
    } else{
      next_A = A[x+1];
    }
    if (y == Y-1){
      next_B = -1;
    } else{
      next_B = B[y+1];
    }
    if (z == Z-1){
      next_C = -1;
    } else{
      next_C = C[z+1];
    }
    if (next_A >= next_B && next_A >= next_C){
      x++;
    }
    else if (next_B >= next_C && next_B >= next_A){
      y++;
    }
    else{
      z++;
    }
    cout << x << y << z << endl;
  }
  sort(output, output + max_K, greater<long>());
  //　出力
  for (int k=0; k<K; k++){
    cout << output[k] << endl;
  }
  return 0;
}
