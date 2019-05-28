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

  void Matrix2D::show() {
    auto A = this;
    cout << "A: xdim=" << A->getXdim() << " ydim=" << A->getYdim() << endl;
    auto mat = A->getMat();
    for(int i=0; i<A->getYdim(); i++){ // ydim is rows
      cout << "[ ";
      for(int j=0; j<A->getXdim(); j++){
        cout << mat[i][j] << " ";
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
  static char daytab[2][5] = {
    {'a','b','c','d','e'},
    {'f','g','h','i','j'}
  };

  int rows=3;
  int cols=4;
  // This must be statically allocated in the data portion.  Does not allow us any flexibility.
  int vals[3][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };

  // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
  int** xs = new int*[rows];
  for(int i=0; i<rows; i++){
    xs[i] = new int[cols];
  }

  auto m1 = new MyMatrix::Matrix2D(xs, rows, cols); // This is not working. It does not accept the xs parameter as 

  // And then initialize the arrays here.
  m1->show(); // Must use arrow for methods.  Methods refer to 'this'?

  
  // Okay, that was painful.  How does cpp handle it's own vector and array data types?



  /**
   * C++ vs C basic syntax:
   *   - references (int&) vs pointers (int*) in C++:
   *         - can not refer directly to a references value (memory address) after creation.
   *         - any use of the references identifier will refer to the associated object.
   *         - references can not be "reseated" to refer to a different object. (this is often done with pointers)
   *         - references can not be NULL (they may refer to some invalid object though)
   *           - hence containers of references are not allowed.
   *         - MUST be initialized on declaration (since can not be reseated).
   *         - Conversion: `int* ptr = &x` will convert the reference to x directly to a pointer.
   *                  and: `int& x = ptr` will convert in the other direction.
   *
   *
   *
   * Other keywords to learn:
   *   - extern: lets compiler know that variable has been declared elsewhere, outside the current scope.
   *             How is this different from using a namespace?  
   *             Allows for data to span mulitple files.  Note the actual declaration doesn't seem to get
   *             any special syntax.
   *   - union
   *   - volatile
   *   - static: Like java.  Only defined once, belongs to the class.
   *   - typedef: is an alias
   *   - struct (in C):
   *   - struct (in C++): (struct is usefull for 'bundling' things, usually data, to raise abstraction)
   *     - difference from union?
   *     - difference from class:
   *       - ONLY difference is the default accessibility of member variables and functions. (struct public, class private)
   *         - This also applies to inheritance, `struct T: Base` == `struct T: public Base` and
   *                                             `class T: Base` == `class T: private Base`
   *     
   * C++ only keywords:
   *   - auto (and decltype??): Allows compiler to deduce type at compile time.  Does not impact run time. 
   *                            NOTE: auto& is required to store a reference to a type (say, int&)
   *   - explicit: Applied to constructors and conversion operators. Prevents the compiler from doing
   *               an implicit parameter conversion.  This implicit parameter conversion is strange 
   *               behaviour indeed, and could be something to watch out for.  explicit just keeps the 
   *               implicit paramter conversion from hiding errors.
   *   - operator: For overloading operators. Like haskell.
   *   - this: References the current instance of a class, in the current scope.  Is a points, use with arrow notation.
   *   - delete: and delete[] for arrays.  Delete an object or array that was created by the new expression. (dynamic allocation only)
   *             NOTE: Make sure that you only delete each object once.
   *   - typeid: in <typeinfo> header.
   *   - dynamic_cast
   *   - new: dynamic allocation of memory.
   *   - template: 
   *   - inline: Expands the function inline instead of making a procedure call.  Effective for small procedures. Note that this can increase
   *             the memory footprint of a program if the inlined functions are large.  Best suited for small, macro-esc functions.
   *   - mutable
   *   - typename
   *   - static_cast
   *   - friend: can access private and protected members of other class that defines it as friend. Usefull when otherwise we 
   *             would require a bunch of public get() methods that are only used in one other class.
   *             note: friendship is one-way and NOT inherited.
   *             note: no equivalent functionality in Java.
   *   - public: Is it like java?  Are classes public by default?
   *   - protected: is it like java? Does it apply to methods?
   *   - using: is this only for namespaces?  Is this only for scoping?
   *   - reinterpret_cast
   *   - throw: What types of exceptions?
   *   - catch
   *   - try
   *   - virtual: non-static member function (ie associated with the instance of a class) that supports
   *              dynamic dispatch (ie can be overriden by descendant classes).  Appears in declaration 
   *              (ie, usually in header file).
   *   - override: used to override virtual functions. NOTE: override is optional, and all override functions
   *               are ALSO virtual!
   *   - const_cast
   *   - wchar_t
   *
   *   Resources:
   *   - https://isocpp.org/wiki/faq/ctors#named-parameter-idiom (whole site is generally a good resource)
   *   - https://isocpp.org/wiki/faq/ctors#explicit-ctors
   *   - https://isocpp.org/wiki/faq/ctors#ctor-work-right (constructors and desctructors, still working on it)
   */

}
