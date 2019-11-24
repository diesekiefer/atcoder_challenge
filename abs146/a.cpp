#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<string> Week{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

  for (int i=0; i<7; i++){
    if (S == Week[i]){
      cout << 7 - i << endl;
    }
  }

  return 0;
}
