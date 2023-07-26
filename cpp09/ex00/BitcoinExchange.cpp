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
  if (!std::isdigit(s[s.size() - 1])) ret = false;

  return ret;
}

std::string BitcoinExchange::getKey(std::string s, char delimiter) {
  size_t findPos = s.find(delimiter);
  if (findPos == std::string::npos) throw std::runtime_error("cannot find delimiter");
  s = s.substr(0, findPos);
  trimFrontBack(s);
  return s;
}

float BitcoinExchange::getValue(std::string s, char delimiter) {
  size_t findPos = s.find(delimiter);
  if (findPos == std::string::npos) throw std::runtime_error("fatal: cannot find delimiter");
  trimFrontBack(s);
  s = s.substr(findPos + 1, s.size());
  char *ptr;
  float res = strtof(s.c_str(), &ptr);
  if (*ptr) throw std::runtime_error("invalid value");
  if (res < 0) throw std::runtime_error("not a positive number");
  return res;
}

void BitcoinExchange::loadDatabase() {
  /* Open data.csv */
  std::ifstream dataBase(_DEFAULT_DB_PATH);
  if (!dataBase.is_open()) throw std::runtime_error("fatal: cannot open data.csv");

  std::string       line;

  /* Read data.csv and validate tokens */
  std::getline(dataBase, line);
  while (std::getline(dataBase, line)) {
    std::string key = BitcoinExchange::getKey(line, ',');
    if (!validateDate(key)) throw std::runtime_error("fatal: parsing error in data.csv (invalid date)");
    float value = BitcoinExchange::getValue(line, ',');
    this->_map[key] = value;
  }
}

void  BitcoinExchange::parseInputValues(std::string file) const {
  std::ifstream inFile(file.c_str());
  if (!inFile.is_open()) throw std::runtime_error("fatal: cannot open " + file);
  
  std::string       line;
  bool              validated;

  /* Read input.csv and validate key-value */
  std::getline(inFile, line);
  while (std::getline(inFile, line)) {
    std::string tmp = line.substr(0, line.find("|"));
    trimFrontBack(tmp);
    std::cout << tmp << " => ";
    try {
      std::string key = BitcoinExchange::getKey(line, '|');
      if (!(validated = validateDate(key))) {
        std::cout << "bad input";
      }
      else {
        float value = BitcoinExchange::getValue(line, '|');
        if (value > 1000) throw std::runtime_error("number too large");
        std::cout << value << " = " << value * (this->_map.lower_bound(key))->second;
      }
    }
    catch (std::exception& e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
}

const std::map<std::string, double>& BitcoinExchange::getDataBase() const {
  return this->_map;
}
