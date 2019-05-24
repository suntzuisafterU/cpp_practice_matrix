#include <iostream>
#include <iomanip>
#include "Common.hpp"

using namespace std;
using std::setw; // from iomanip

namespace MyMatrix {

  /**
   * The scope specifier Real2DVector:: is required since the constructor is a static method...
   * 
   */
   Real2DVector::Real2DVector(int x, int y) {
        this->x = x; // I believe these 2 statements are equivalent.
        this->y = y;
      }
// 2 equivalent constructors.
//  Real2DVector::Real2DVector(int x, int y): x(x), y(y) {};

  /**
   * Okay, but here isn't getX an instance method?  What is going on...  Although this definitely makes sense.
   */
  int Real2DVector::getX(){
    return this->x;
  }

  int Real2DVector::getY(){
    return this->y;
  }

  Matrix2D::Matrix2D(int** xs, int xdim, int ydim): xs(xs), xdim(xdim), ydim(ydim) {};

  int Matrix2D::getXdim(){ return this->xdim; }

  int Matrix2D::getYdim(){ return this->ydim; }

  int** Matrix2D::getMat(){ return this->xs; }

  Matrix2D operator + (Matrix2D A, Matrix2D B){
    // Check that they are the corrent size.

    // Then add piecewise.
  }

  void Matrix2D::show(Matrix2D A) {
    cout << "A: xdim=" << A.getXdim() << " ydim=" << A.getYdim() << endl;
    auto mat = A.getMat();
    for(int i=0; i<A.getYdim(); i++){ // ydim is rows
      cout << "[ ";
      for(int j=0; j<A.getXdim(); j++){
        cout << mat[i,j] << " ";
      }
      cout << " ]" << endl;
    }
  }
}

int main(){
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
  MyMatrix::Real2DVector v2 = MyMatrix::Real2DVector(3, 9);
  auto v3 = MyMatrix::Real2DVector(2,9);
  cout << v3.getX() << endl;

  // https://stackoverflow.com/questions/8108416/excess-elements-of-scalar-initializer-for-pointer-to-array-of-ints
  // Working on multi-dimensional arrays and pointers.
  static char daytab[2][13] = {
  
  }

  int** xs = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };

  auto m1 = new MyMatrix::Matrix2D(xs, 3, 4); // This is not working. It does not accept the xs parameter as 

  /**
   * Other keywords to learn:
   *   - extern: lets compiler know that variable has been declared elsewhere, outside the current scope.
   *             How is this different from using a namespace?  
   *             Allows for data to span mulitple files.  Note the actual declaration doesn't seem to get
   *             any special syntax.
   *   - union
   *   - volatile
   *   - static: Like java.  Only defined once, belongs to the class.
   *   - typedef: is an alias
   *   - struct: difference from union?
   * C++ only keywords:
   *   - explicit: Applied to constructors and conversion operators. Prevents the compiler from doing
   *               an implicit parameter conversion.  This implicit parameter conversion is strange 
   *               behaviour indeed, and could be something to watch out for.  explicit just keeps the 
   *               implicit paramter conversion from hiding errors.
   *   - operator
   *   - this
   *   - delete
   *   - typeid
   *   - dynamic_cast
   *   - new
   *   - template: 
   *   - inline
   *   - mutable
   *   - typename
   *   - static_cast
   *   - friend
   *   - public
   *   - protected: is it like java? Does it apply to methods?
   *   - using: is this only for namespaces?  Is this only for scoping?
   *   - reinterpret_cast
   *   - throw: What types of exceptions?
   *   - catch
   *   - try
   *   - virtual
   *   - const_cast
   *   - wchar_t
   */

}
