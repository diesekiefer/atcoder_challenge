#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, a2, a3;
  cin >> a1;
  cin >> a2;
  cin >> a3;
  vector<int> A{a1, a2, a3};
  int min_cst = 9999;
  int tmp;
  for (int i=0; i<3; i++){
    tmp = 0;
    for (int j=0; j<3; j++){
      if (i == j){
        continue;
      }
      tmp = 0;
      tmp += abs(A[i] - A[j]);
      for (int k=0; k<3; k++){
        if (j == k){
          continue;
        }
        if (i == k){
          continue;
        }
        tmp += abs(A[j] - A[k]);
        if (tmp < min_cst){
          min_cst = tmp;
        }
      }
    }
  }
  cout << min_cst << endl;
}
