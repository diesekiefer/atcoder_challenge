
#include <iostream>
#include <string>
using namespace std;

int main(){
  int A, B;
  cin >> A;
  cin >> B;

  int out = 0;
  if (A > B){
    out += A;
    A -= 1;
  } else{
    out += B;
    B -= 1;
  }

  if (A > B){
    out += A;
  } else{
    out += B;
  }

  cout << out << endl;
  return 0;
}
