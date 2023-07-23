#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);
  ~BitcoinExchange();

  static void csvParser(std::string&, std::map<std::string, float>&,
                        char delimiter);
  void loadDatabase(std::string&);

 private:
  std::map<std::string, float> _mapDatabase;
  std::map<std::string, float> _mapInFile;

  static bool validateDate(const std::string&);
};

#endif
