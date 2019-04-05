#include <cmath>
#include <cstdio>

double calcSqrt(int a) {
  if (a >= 0) {
    return sqrt(a);
  } else {
    // получим ошибку компиляции что return без значения
    // return;
    // получим ошибку несовместимости типов
    // return &a;
    // return 0;
  }
}

bool isDigit(unsigned char ch) {
  return (ch >= 48 && ch <= 57);
}

auto calcSumm(int a, int b, int c) -> decltype(a + b + c) {
  return a + b + c;
}


/*auto errorDeducation(bool val) {
  if (val) {
    return 123; // возвращаемый тип int
  } else {
    return 3.14f;   // ошибка: возращаемый тип float
  }
}*/

int main(int argc, char const *argv[]) {
  printf("Sqrt(10) == %lf\n", calcSqrt(10));
  printf("isDigit('a') == %s\n", isDigit('a') ? "true" : "false");
  printf("isDigit('1') == %s\n", isDigit('1') ? "true" : "false");
  printf("isDigit('&') == %s\n", isDigit('&') ? "true" : "false");
  printf("calcSumm(10, 5, 15) == %d\n", calcSumm(10, 5, 15));
  // printf("errorDeducation(0) == %d\n", errorDeducation(false));
  return 0;
}
