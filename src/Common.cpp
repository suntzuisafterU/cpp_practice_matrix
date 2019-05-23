#include <iostream>
#include "Common.hpp"

using namespace std;

namespace MyMatrix {

  /**
   * The scope specifier Real2DVector:: is required since the constructor is a static method...
   * 
   */
  Real2DVector::Real2DVector(int x, int y) {
        this->x = x; // I believe these 2 statements are equivalent.
        this->y = y;
      }

  /**
   * Okay, but here isn't getX an instance method?  What is going on...  Although this definitely makes sense.
   */
  int Real2DVector::getX(){
    return this->x;
  }

  int Real2DVector::getY(){
    return this->y;
  }

}

int main(int argc, char* argv[]){
  int x = 4;
  int y = 8;
  // What is special about using auto?
  auto myVector = new MyMatrix::Real2DVector(x, y); // Why is this a pointer?
  cout << myVector->getX() << endl; // What is the difference between . and -> notation?
  cout << myVector->getY() << endl; // This 
  /** 
   * Use -> to operate on a pointer to an object.  auto seems to produce a pointer. Foo* foo; foo->bar = 5;
   * Use . on an instance of an object.  Ex. Foo foo; foo.bar = 5;
   * Use :: for accessing static, STATIC, variables and members of a class/struct or namespace.
   */

}
