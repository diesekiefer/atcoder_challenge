#include<bits/stdc++.h>
using namespace std;

int get_digit(long long N){
  long long digit=0;
  while(N != 0){
    N /= 10;
    digit++;
  }
  return digit;
}

int is_buy(long long A, long long B, long long X, long long N){
  if (A * N + B * get_digit(N) <= X){
    return 1;
  }
  return 0;
}

int main(){
  long long A, B, X;
  cin >> A >> B >> X;

  long long OK = 0;
  long long ng = 1000000001;

  while(abs(OK - ng) > 1){
    long long mid = (OK + ng) / 2;
    if (is_buy(A, B, X, mid)){
      OK = mid;
    } else{
      ng = mid;
    }
  }
  cout << OK << endl;
  return 0;
}
