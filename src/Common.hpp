#ifndef REAL2DVECTOR_H
#define REAL2DVECTOR_H

namespace MyMatrix {

  class Real2DVector {
    private:
      int x;
      int y;

    public:
      Real2DVector(int x, int y); 
      int getX();
      int getY();
  };

  class Matrix2D {
    private:
      int** xs; // int** is 2D array?
      int xdim, ydim;
    public:
      Matrix2D(int** xs, int xdim, int ydim); // Prevents implicit parameter conversion.
      int getXdim();
      int getYdim();
      int** getMat();
      void show(Matrix2D A);

  };
}

#endif
