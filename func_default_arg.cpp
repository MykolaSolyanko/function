#include <cstdio>

// компилятор выдаст ошибку компиляции,
// в том что мы пропустили значение по умолчанию для второго аргумента
/*long calc(int a = 10, int b) {
  return a + b;
}*/

long calc(int a, int b = 5) {
  return a + b;
}

int main(int argc, char const *argv[]) {
    printf("calc(10, 20) == %ld\n", calc(10, 20)); // 30
    // в примере параметр b будет инициализирован значением по умолчанию 5
    printf("calc(10, 5) == %ld\n", calc(10)); // 15
    return 0;
}
