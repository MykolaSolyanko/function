#include <iostream>
 
unsigned long long fibNumber (unsigned number) {
  if (number < 2) {
    return number;
  }  
  return fibNumber(number - 1) + fibNumber(number - 2);
}
 
int main() {
  std::cout << fibNumber(6);
  return 0;
}