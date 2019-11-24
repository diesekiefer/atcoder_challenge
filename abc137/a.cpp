#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;

  int sum = A + B;
  int sub = A - B;
  int time = A * B;

  if (sum > sub){
    if (sum > time){
      cout << sum << endl;
      return 0;
    } else{
      cout << time << endl;
      return 0;
    }
  } else{
    if (sub > time){
      cout << sub << endl;
      return 0;
    } else{
      cout << time << endl;
      return 0;
    }
  }
}
