#include "CallNumber.hpp"
#include <iostream>

int main(void) {
  CallNumber cn1("QA", 1, "N13", 0);
  CallNumber cn2("B", 1, "A", 1);
  std::cout << cn1.compare(cn2) << std::endl;
  return 0;
}
