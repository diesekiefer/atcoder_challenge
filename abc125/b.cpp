#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  int V[N], C[N];
  for (int i=0; i<N; i++){
    cin >> V[i];
  }
  for (int i=0; i<N; i++){
    cin >> C[i];
  }

  int sum = 0;
  for (int i=0; i<N; i++){
    if (V[i] - C[i] > 0){
      sum += V[i] - C[i];
    }
  }
  cout << sum << endl;
  return 0;
}
