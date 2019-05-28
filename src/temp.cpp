#include<iostream>

using namespace std; 

int main() 
{ 
  int x = 4; 
  int* y = &x;
  auto ptr = &x;
  int& z = x;

  cout << typeid(x).name() << endl 
    << typeid(y).name() << endl 
    << typeid(ptr).name() << endl
    << typeid(z).name() << endl; 

  float b = 1.0f;
  int i = static_cast<int>(b);
  int& j = static_cast<int&>(b);
  cout<<i<<endl
    <<j<<endl;

  return 0; 
} 
