#include <cstdio>

void justPrint(int a, int b) {
  printf("%s\n", __func__);
  a = 10;
  printf("a == %d\n", a);
  b = 25;
  printf("b == %d\n", b);
}

auto multiply(int a, int b) /*-> decltype(a * b)*/ { // trailing return type начиная с C++14 не объязателен
  printf("%s\n", __func__);
  return a * b;
}

int main(int argc, char const *argv[]) {
  int a = 40;
  int b = 88;
  printf("%s\n", __func__);
  printf("a == %d\n", a);
  printf("b == %d\n", b);
  justPrint(a, b);
  printf("%s\n", __func__);
  printf("a == %d\n", a);
  printf("b == %d\n", b);
  printf("multiply(%d, %d) == %d\n", a, b, multiply(a, b));
  return 0;
}
