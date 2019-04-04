#include <cstdio>

void print(unsigned a) {
  printf("%s a = %d\n", a);
}

void print(int a) = delete;

int main(int argc, char const *argv[]) {
  print(10u);
  // ошибка компиляции использования удаленной функции void print(int)
  // print(10);
  return 0;
}
