#include "BitcoinExchange.hpp"

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

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

static void trimFrontBack(std::string& s) {
  s.erase(s.find_last_not_of(' ') + 1);
  s.erase(0, s.find_first_not_of(' '));
}

bool BitcoinExchange::validateDate(const std::string& s) {
  bool        ret     = true;
  const char* format  = "%Y-%m-%d";
  struct tm   tp;

  if (strptime(s.c_str(), format, &tp) == NULL) ret = false;

  return ret;
}

void BitcoinExchange::loadDatabase() {
  /* Open data.csv */
  std::ifstream dataBase(_DEFAULT_DB_PATH);
  if (!dataBase.is_open()) throw std::runtime_error("fatal: cannot open data.csv");

  std::string       line;

  /* Read data.csv and validate tokens */
  std::getline(dataBase, line);
  while (std::getline(dataBase, line)) {
    size_t findPos = line.find(",");
    if (findPos == std::string::npos) throw std::runtime_error("fatal: parsing error in data.csv (no delimiter)");
    std::string key = line.substr(0, findPos);
    if (!validateDate(key)) throw std::runtime_error("fatal: parsing error in data.csv (invalid date)");
    std::string tmp = line.substr(findPos + 1, line.size());
    trimFrontBack(tmp);
    std::cout << "res: " << tmp <<std::endl;
    std::stringstream ss; 
    ss << tmp;
    double value;
    ss >> value;
    this->_map[key] = value;
    std::cout << key << "," << this->_map[key] << std::endl;
  }
}

const std::map<std::string, double>& BitcoinExchange::getDataBase() const {
  return this->_map;
}
