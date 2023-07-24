#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "fatal: invalid arguments" << std::endl;
    std::cerr << "usage: ./RPN [expr]" << std::endl;
    return 1;
  }

  RPN obj = RPN();
  std::string input = argv[1];

  try {
    obj.parse(input);
    obj.operate();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
