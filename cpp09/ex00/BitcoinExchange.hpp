#ifndef __BITCOIN_EXCHANGE_HPP__
# define __BITCOIN_EXCHANGE_HPP__

# include <map>
# include <string>

class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);
    ~BitcoinExchange();

  private:
    std::map<std::string, float> _map;

};

#endif
