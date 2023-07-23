#include "BitcoinExchange.hpp"

#include <bits/types/struct_tm.h>
#include <cctype>
#include <stdlib.h>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>

static int errLine;

/* Default constructor and destructor */
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

/* Copy constructor and copy assignment operator */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _mapDatabase(other._mapDatabase), _mapInFile(other._mapInFile) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  if (this != &rhs) {
    this->_mapDatabase = rhs._mapDatabase;
    this->_mapInFile = rhs._mapInFile;
  }
  return *this;
}

/* Utilities */
static std::string getHeaderText() {
  std::string res =
      "*============================*\n\
| EXTREMELY USEFUL ERROR LOG |\n\
*============================*\n\n";
  return res;
}

static void saveErrorLog() {
  remove("error.log");

  std::string header = getHeaderText();
  std::ofstream outFile("error.log");

  outFile << header;
  outFile << __FILE__ << ":" << errLine - 1 << std::endl;
  outFile << strerror(errno) << std::endl;
}

static std::string trimWhiteSpaces(std::string s) {
  s.erase(s.find_last_not_of(' ')+1);
  s.erase(0, s.find_first_not_of(' '));
  return s;
}

/* Member functions */
bool BitcoinExchange::validateDate(const std::string& s) {
  bool ret = true;
  const char* format = "%Y-%m-%d";
  struct tm timedate;

  if (strptime(s.c_str(), format, &timedate) == NULL) ret = false;

  return ret;
}

void BitcoinExchange::csvParser(std::string& inFile,
                                std::map<std::string, float>& map,
                                char delimiter) {
  std::ifstream dataCsv;
  std::string line;

  (void)map;
  dataCsv.open(inFile.c_str());
  if (!dataCsv.is_open()) {
    errLine = __LINE__;
    saveErrorLog();
    throw std::runtime_error("fatal: unable to open " + inFile +
                             " (logs saved at: ./error.log)");
  }
  std::getline(dataCsv, line);
  if (line.find(delimiter) == std::string::npos) {
    throw std::runtime_error("fatal: parsing error: invalid headers in csv");
  }
  while (std::getline(dataCsv, line)) {
    /* std::cout << line << std::endl; */
    size_t findPos = line.find(delimiter);
    if (findPos != std::string::npos) {
      std::string res = trimWhiteSpaces(line.substr(0, findPos));
      std::cout << res << std::endl;
    } else {
      std::cout << line << ": parsing error" << std::endl;
    }
  }
}

void BitcoinExchange::loadDatabase(std::string& inFile) {
  std::string dataCsv = "./data.csv";

  BitcoinExchange::csvParser(dataCsv, this->_mapDatabase, ',');
  BitcoinExchange::csvParser(inFile, this->_mapInFile, '|');
}
