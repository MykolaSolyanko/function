#include <iostream>
#include <algorithm>

// приходилось писать до с++14го

/*#include <functional>

std::function<long(int, int)> make_lambda() {
    return [](int a, int b = 20) -> long {
        return a + b;
    };
}*/

auto make_lambda() {
  return [](int a, int b = 20) {
           return a + b;
         };
}

auto make_lambda_several_ret() {
  return [](bool flag) -> long double {
           if (flag)
             return 10.25;
           else
             return 14;
         };
}

auto make_lambda_with_attr() {
  return [](int a, int b) [[deprecated("mult is deprecated")]] {
           return a * b;
         };
}

auto problem_with_ref(int& a) {
  int b = 90;
  return [&a, &b]() {
    std::cout << b << std::endl;
    ++a;
  };
}

auto generic_lambda() {
  return [](auto a, auto b) {
    return a + b;
  };
}

int main(int argc, char const *argv[]) {
  auto lambda = make_lambda();
  std::cout << lambda(1, 5) << std::endl;
  std::cout << lambda(10, 5) << std::endl;
  std::cout << lambda(1) << std::endl;

  std::cout << make_lambda_several_ret()(true) << std::endl;
  std::cout << make_lambda_several_ret()(false) << std::endl;

  int a = 40;
  // без mutable вы не сможете поменять значение copy_a
  [&new_a = a, copy_a = a](int param) mutable {
    new_a = param;
    ++copy_a;
  }(20);

  std::cout << a << std::endl;

  auto ref = problem_with_ref(a);
  ref();
  std::cout << a << std::endl;
  std::cout << generic_lambda()(10, 10) << std::endl;
  std::cout << generic_lambda()(10.40, 10) << std::endl;

  unsigned array[5] {5, 4, 3, 2, 1};
  std::sort(array, &array[5], [](unsigned a, unsigned b) {return a < b;});
  for (auto val : array) {
    std::cout << val << std::endl;
  }

  return 0;
}
