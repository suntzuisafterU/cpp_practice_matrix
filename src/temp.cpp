#include<iostream>

using namespace std; 

int main() 
{ 
    int x = 4; 
    int* y = &x;
    auto ptr = &x;

    cout << typeid(x).name() << endl 
         << typeid(y).name() << endl 
         << typeid(ptr).name() << endl; 
  
    return 0; 
} 
