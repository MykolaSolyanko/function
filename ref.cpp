#include <iostream>
#include <cassert>

const int& cref_local() {
  int a = 90;
  return a;
}

void swap_ref_ptr(int* &ptr1, int* &ptr2) {
  int* ptr_tmp = ptr1;
  ptr1 = ptr2;
  ptr2 = ptr_tmp;
}

long summ(const int& a, const int& b) {
  return a + b;
}

int& static_ref() {
  static int ref = 1;
  printf(__func__);
  printf("\nref == %d\n", ref);
  return ref;
}

int main(int argc, char const *argv[]) {
  int value1 = 40;
  // в этот момент происходит связь(расшаривание адрессов)
  int& ref1 = value1;
  assert(&ref1 == &value1);

  int value3 = 40;
  // в этом месте просто происходит изменения значения ссылки,
  // ref1 все еще указывает на value1
  ref1 = value3;
  assert(&ref1 != &value3);

  const int& cref = value1;
  
  // нельзя менять константное значение
  // cref = value3;

  // но можно так))
  const_cast<int &>(cref) = 90;

  assert(cref == 90);
  assert(value1 == 90);

  int array[3] {1, 2, 3};
  int (&ref_arr)[3] = array;
  ref_arr[1] = 90;
  assert(ref_arr[1] == array[1]);

  const int& rvref = 7;

  assert(rvref == 7);

  // такое не будет работать для указателя
  // const int* ptr = (int *)(&7);

  int *ptr = nullptr;

  // не вызовет падение программы
  int& ref_ptr = *ptr;

  // а так программа упадет
  //ref_ptr = 2;

  // в большинстве случаев получим seg fault
  // assert(cref_local() == 90);

  int value_ptr_sw1 = 40;
  int value_ptr_sw2 = 80;
  int *ptr_sw1 = &value_ptr_sw1;
  int *ptr_sw2 = &value_ptr_sw2;
  swap_ref_ptr(ptr_sw1, ptr_sw2);

  assert(*ptr_sw1 == 80);
  assert(*ptr_sw2 == 40);

  assert(summ(value_ptr_sw1, value_ptr_sw2) == 120);
 
  assert(summ(7, 2) == 9);

  ++static_ref();
  ++static_ref();
  ++static_ref();
  ++static_ref();
  int &ref_func = static_ref();
  ++ref_func;
  static_ref();
  return 0;
}
