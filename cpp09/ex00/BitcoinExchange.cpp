#include <cstdlib>
#include <stdlib.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

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
	std::string res = "*============================*\n\
| EXTREMELY USEFUL ERROR LOG |\n\
*============================*\n\n";
	return res;
}

static void saveErrorLog() {
	remove("error.log");

	std::string 	header = getHeaderText();
	std::ofstream 	outFile("error.log");

	outFile << header;
	outFile << __FILE__ << ":" << errLine - 1 << std::endl;
	outFile << strerror(errno) << std::endl;
}

/* Member functions */
void BitcoinExchange::csvParser(std::string &inFile) {
	std::ifstream 	dataCsv;
	std::string 	line;

	dataCsv.open(inFile.c_str());
	if (!dataCsv.is_open()) {
		errLine = __LINE__;
		saveErrorLog();
		throw std::runtime_error("fatal: unable to open " + inFile + " (logs saved at: ./error.log)");
		/* throw std::runtime_error(inFile + ": " + strerror(errno)); */
	}
	std::getline(dataCsv, line);
	while (std::getline(dataCsv, line)) {
		std::cout << line << std::endl;
	}
}

void BitcoinExchange::loadDatabase() {
	std::string inFile = "randomfile";

	BitcoinExchange::csvParser(inFile);
}
