#include <stdio.h>
#include <math.h>

void update(int* a, int* b){
  int c = *a + *b;
  int d = abs((float)*a - *b);
/*   a = &c; */ 
/*   b = &d; 
 *   These were both wrong.  I was changing the local scope of my pointer,
 *   NOT the value at the pointer referenced by the outer scope!! */
  *a = c;
  *b = d;
}
