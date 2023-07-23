#include <cstdlib>
#include <exception>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "fatal: invalid arguments" << std::endl;
    std::cerr << "usage: ./btc [path_to_database]" << std::endl;
    return EXIT_FAILURE;
  }
  (void)argv;
  BitcoinExchange btc = BitcoinExchange();
  try {
    std::string puta = argv[1];
    btc.loadDatabase(puta);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
