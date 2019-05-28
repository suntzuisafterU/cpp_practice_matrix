#include <iostream>

int main {
  
}

struct Point {
  int x,y;
  Point(int xx = 0, int yy = 0): x(xx), y(yy) { }
};

using namespace std;

class X {
  public:
    X(int x){
      // Not sure how to make this constructor such that we can make this example work...
    }
};

class Handle {
  private:
    string name;
    X* p;
  public:
    Handle(string n)
      :name(n), p(0) {
        /* acquire X called "name" and let p point to it */
      }
    ~Handle() { delete p; /* releases X called "name" */ }
};

/**
 * Purpose:
 *   - Figure out the difference between all the different constructors that can be called and how
 *     destructors can be invoked.
 * 
 * Questions:
 *   - Does `const T& max(const T& a, const T& b);` call the copy constructors of a and b? Does it call one of them twice?
 *
 * resources: https://isocpp.org/wiki/faq/ctors#ctor-work-right
 */
