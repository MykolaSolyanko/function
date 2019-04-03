#include <cstdio>

void print_ref(int& a) {
  printf("%s a = %d\n", __PRETTY_FUNCTION__, a);
  ++a;
}

void print_ref(const int& a) {
  printf("%s a = %d\n", __PRETTY_FUNCTION__, a);
}

void print_pointer(const int* a) {
  if (a != nullptr) {
    printf("%s a = %d\n", __PRETTY_FUNCTION__, *a);
  }
}

// будет ошибка компилятора, т.к. константность указателя не играет роли
/*
void print_pointer(const int* const a) {
  if (a != nullptr) {
    printf("%s a = %d\n", __PRETTY_FUNCTION__, *a);
  }
}*/

void print_pointer(int* a) {
  if (a != nullptr) {
    printf("%s a = %d\n", __PRETTY_FUNCTION__, *a);
    ++*a;
  }
}

void print_pointer(int a) {
  printf("%s a = %d\n", __PRETTY_FUNCTION__, a);
}

void swap_ptr(int* &ptr1, int* &ptr2) {
  printf("%s\n", __PRETTY_FUNCTION__);
  int *tmp_ptr = ptr1;
  ptr1 = ptr2;
  ptr2 = tmp_ptr;
}

void swap_ptr(int** ptr1, int** ptr2) {
  printf("%s\n", __PRETTY_FUNCTION__);
  int *tmp_ptr = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp_ptr;
}

void swap_ptr(int* const * ptr1, int* const * ptr2) {
  printf("%s\n", __PRETTY_FUNCTION__);
}

int main(int argc, char const *argv[]) {
  int a = 1;
  const int b = 1;
  print_ref(a);
  print_ref(a);
  print_ref(2);
  print_pointer(&a);
  print_pointer(&b);
  print_pointer(0);
  // получим ошибку, т.к. есть неоднозначность какую функцию вызвать
  // print_pointer(nullptr);

  int swap_1 = 100;
  int swap_2 = 40;
  int *ptr1 = &swap_1;
  int *ptr2 = &swap_2;
  swap_ptr(ptr1, ptr2);
  printf("swap_1 = %d swap_2 = %d\n", *ptr1, *ptr2);
  swap_ptr(&ptr1, &ptr2);
  printf("swap_1 = %d swap_2 = %d\n", *ptr1, *ptr2);

  int * const * cptr1 = &ptr1;
  int * const * cptr2 = &ptr2;
  swap_ptr(cptr1, cptr2);
  return 0;
}
