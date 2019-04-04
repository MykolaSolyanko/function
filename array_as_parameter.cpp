#include <stdio.h>

#define SIZE_ARRAY(array) sizeof((array)) / sizeof((array)[0])

void incorrect_print_array(int array[5]/*the same int array[]*/) {
  // результат будет не такой как ожидается(см. раздел с указателями)
  printf("array size in incorrect function %zu\n", SIZE_ARRAY(array));
  for (size_t i = 0; i < 5; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void correct_print_array(int array[], size_t length) {
  for (size_t i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void buble_sort(int (&array)[5]) {
  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 5 -1; ++j) {
        if (array[j] > array[j + 1]) {
          int tmp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = tmp;
        }
    }
  }
}

// при передачи многомерного массива первый уровень игнорируеться компилятором как при работе с одномерным массивом
// а вот размер второго уровня обьязателен, если его указать или передать неверный размер то будет ошибка компиляции
void print_2D_array(int array[][2], size_t length_first_dim) {
  for (size_t i = 0; i < length_first_dim; ++i) {
    for (size_t j = 0; j < 2; ++j) {
      printf("%5d", array[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int array[5] = {5, 4, 3, 2, 1};
  int array2[7] = {7, 6, 5, 4, 3, 2, 1};
  printf("array size is %zu\n", SIZE_ARRAY(array));
  buble_sort(array);
  // buble_sort(array2); compiler error initialization of reference of type ‘int (&)[5]’ from expression of type ‘int [7]’

  incorrect_print_array(array); // print 1 2 3 4 5
  // программа компилируеться без ошибок, так как по умолчанию размер массива игнорируеться
  incorrect_print_array(array2); // print 7 6 5 4 3

  correct_print_array(array2, SIZE_ARRAY(array2)); // print 7 6 5 4 3 2 1

  int array2D[][2] = {{1,2}, {3,4}, {5,6}};
  print_2D_array(array2D, SIZE_ARRAY(array2D));
  // int array2D_error[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  // print_2D_array(array2D_error, SIZE_ARRAY(array2D_error)); // compilation error, несовместимость типов(размеров)
  return 0;
}