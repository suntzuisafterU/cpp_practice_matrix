#include "Matrix.hpp"

using std::string;

/**
 * main function to run tests only.
 */
int main() {
  /* How do we initialize a C style 2D array and pass around a pointer to it?
   * Is this even efficient, or even a good idea to do in C? */

  /* What is wrong with my first instinct for creating a new Matrix:
   *   `_Matrix::Matrix m1 = new _Matrix::Matrix(X);`
   *   Well, compiler says we are actually returning a Matrix*
   */
  _Matrix::Matrix* m1 = new _Matrix::Matrix(3, 4); // 3 row, 4 col matrix
  // Matrix* m2 = new Matrix(); // Error, not using the namespace, see below.

  m1->show();

  // Does the ~Matrix destructor implicitly get called at the end of our program?
};

/**
 * THIS WAS AN ERROR!
 *   `using namespace _Matrix;`
 * we are not using the namespace, we are defining it.
 */ 

namespace _Matrix {
  /**
   * Trying to define a basic constructor.
   * What was wrong with my first intuition here:
   *   `Matrix(int row, int col) { ... };`
   * ANSWER: I made this mistake before.  It is the same as
   */ 
  Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->A = (int *)malloc(rows * cols * sizeof(int));
  };

  Matrix::~Matrix(){
    free(this->A);
  };

  /**
   * What is the proper specification of a function within a custom namespace?
   * This was my first intuition and error: `string Matrix::show() { ... };`
   * ANSWER: Was missing the namespace specifier.  Must use namespace and class
   * scope specifiers like this:
   *   string _Matrix::Matrix::show() { ... };
   * Solution: `using namespace _Matrix`
   */
  void Matrix::show() { // NOTE: This is from the namespace _Matrix
    /* How do we build a string in C++ ? */
    /* How do we return null in C++ ? */ // return NULL;
    for(int j=0; j<this->cols; j++){
      printf("[ ");
      for(int i=0; i<this->rows; i++){
        printf(" %d ", this->A[i*j + j]);
      }
      printf(" ]\n");
    }
    // throw new Utils::NotImplementedException();
  };
}
