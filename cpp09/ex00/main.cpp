#include <cstdlib>
#include <iostream>

#include "BitcoinExchange.hpp"

static int errUsage() {
    std::cerr << "fatal: invalid arguments" << std::endl;
    std::cerr << "usage: ./btc [path_to_input.csv]" << std::endl;
    return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {

  /* Check correct usage */
  if (argc != 2) return errUsage();

  BitcoinExchange btc = BitcoinExchange();

  (void) argv;
  try {
    btc.loadDatabase();
  }
  catch (std::exception& e) {
    std::cerr << "fatal: error while parsing data.csv (" << e.what() << ")" << std::endl;
    return 1;
  }
  try {
    btc.parseInputValues(argv[1]);
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
