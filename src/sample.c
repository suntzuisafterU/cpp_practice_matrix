

int main() 
{ 
  int x = 4; 
  int* ptr = &x;
  int y = *ptr;
  // int& z = x; // Error, int& is not a valid LHS type specifier in C.

  float b = 1.0f;
  int i = (int)b;

  return 0; 
} 

// Error, int& is not recognized in C.
// int func(int& x){
//   return 0;
// }
