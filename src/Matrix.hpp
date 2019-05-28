#include <iostream> // for std::cout
#include <iomanip> // for std::setw
#include "Utils.cpp" /* How do we include a local file?? */

using std::setw;
using std::string;

/**
 * All questions in this file will be fundamental and should be added to a memory palace.
 * Do not remove questions.
 */
namespace _Matrix {
  /**
   * How is inheritance handled again?
   */
  class Matrix {
    public:
      /**
       * Basic matrix.
       */
      Matrix(int row, int col);
      ~Matrix();

      /**
       * Is there a difference in returning a string, or a string& ?
       */
      void show();

    private:
      int rows; // Record dimensions
      int cols;
      int* A;
  };
}
