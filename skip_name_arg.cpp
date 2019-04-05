#include <cstdio>
#define __UNUSED__

int calc(int, int = 5);

void movePerson(float x, float y, float /*z*/__UNUSED__) {
  printf("Move person x == %f y == %f\n", x, y);
}

int main(int argc, char const *argv[]) {
    printf("calc(5, 20) == %d\n", calc(5, 20));
    printf("calc(5, 5) == %d\n", calc(5));
    movePerson(0.5f, 1.5f, 1.1f);
    return 0;
}

int calc(int a, int b) {
  return a + b;
}
