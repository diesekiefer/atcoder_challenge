
#include <iostream>
#include <string>
using namespace std;

int main(){
  int A, B, C;
  cin >> A;
  cin >> B;
  cin >> C;

  if (A < B){
    if (A < C && C < B){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  } else{
    if (B < C && C < A){
      cout << "Yes" << endl;
    } else{
      cout << "No" << endl;
    }
  }
  return 0;
}
