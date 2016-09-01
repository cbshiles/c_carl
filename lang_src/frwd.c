/* typedef struct name{}t_ */
/* struct_name */

struct bar;

struct foo{
  struct bar *e;
};

#include <stdio.h>

struct bar{
  struct foo *f;
};

int main(){
  struct bar b;
  struct foo f;
  b.f = &f;
  f.e = &b;
  
  printf("%d\n", b.f == &f);
  return 0;
}
