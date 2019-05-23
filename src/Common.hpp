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
}

#endif
