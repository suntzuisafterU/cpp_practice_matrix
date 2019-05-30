#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  int* arr = (int*)malloc(sizeof(int) * N);
  int k;
  int i=N;
  while(cin >> k){
    i--;
    arr[i] = k;
  }
  for(int j=0; j<N; j++){
    cout << arr[j] << " " ;
  }

  return 0;
}

