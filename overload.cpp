#include <cstdio>

void print(int a, int b) {
  printf("%s  a = %d, b = %d\n", __PRETTY_FUNCTION__, a, b); 
}

// не скомпилируеться т.к. тип передачи параметра по значению не играет роли const или не const
/*void print(const int a, int b) {
  printf("%s a = %d, b = %d", __func__, a, b); 
}*/

void print(float a, float b) {
  printf("%s a = %f, b = %f\n", __PRETTY_FUNCTION__, a, b); 
}

void print(double a, double b) {
  printf("%s a = %f, b = %f\n", __PRETTY_FUNCTION__, a, b); 
}

// для компилятора это будет неоднозначным такое определение
// т.е. перегрузка невозможна на основе возращаемого значения
/*long double print(double a, double b) {
  printf("%s a = %f, b = %f\n", __PRETTY_FUNCTION__, a, b); 
  return a + b;
}*/

void default_overload(int x) {
  printf("%s x = %d\n", __PRETTY_FUNCTION__, x); 
}

void default_overload(int x, int y = 40) {
  printf("%s x = %d, y = %d\n", __PRETTY_FUNCTION__, x, y); 
}

int main(int argc, char const *argv[]) {
  print(10, 20);
  print(10.90f, 20.90f);
  print(10.90, 20.90);
  /*
   не скомпилируеться, т.к. компилятор не найдет подходящую перегрузку для этой функции,
   и он будет предлагать возможные варианты, но если мы уберем перегрузку для вещественных чисел,
   то компилятор выберит только int используя неявное приведения типа 
  */
  // print(10.90, 20);
  /* 
    в данном случае компилятор выдст ошибку так не знает какую перегрузку вызвать
    т.е. возможен вызов как с одим параметром, так и с двумя (неоднозначность)
    перегрузка с параметром по умолчанию приводит к неоднозначности
  */
  // default_overload(40);
  default_overload(40, 90);
  return 0;
}
