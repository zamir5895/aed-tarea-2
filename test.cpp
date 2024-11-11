#include <iostream>
#include <vector>

#include "hw2.h"

// Función para comparar vectores (si fuera necesario)
template <typename T>
bool operator==(std::vector<T> const& a, std::vector<T> const& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) return false;
  return true;
}

int main() {
  // test1
  Heap<int> h1(true);
  std::cout << "Test 1:" << std::endl;
  std::cout << "Expected output: size = 0" << std::endl;
  std::cout << "Actual output: size = " << h1.size() << std::endl;
  std::cout << std::endl;

  // test2
  Heap<int> h2(false);
  std::cout << "Test 2:" << std::endl;
  std::cout << "Expected output: size = 0" << std::endl;
  std::cout << "Actual output: size = " << h2.size() << std::endl;
  std::cout << std::endl;

  // test3
  Heap<int> h3(true);
  h3.insert(4);
  h3.insert(5);
  h3.insert(1);
  h3.insert(3);
  std::cout << "Test 3:" << std::endl;
  std::cout << "Expected output: size = 4, peek = 1" << std::endl;
  std::cout << "Actual output: size = " << h3.size() << ", peek = " << h3.peek() << std::endl;
  std::cout << std::endl;

  return 0;
}