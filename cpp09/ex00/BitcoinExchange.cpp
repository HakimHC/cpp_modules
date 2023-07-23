#include "BitcoinExchange.hpp"

/* Default constructor and destructor */
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

/* Copy constructor and copy assignment operator */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  if (this != &rhs) this->_map = rhs._map;
  return *this;
}
