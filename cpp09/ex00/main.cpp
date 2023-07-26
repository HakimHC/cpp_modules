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
  btc.solve(argv[1]);
}
