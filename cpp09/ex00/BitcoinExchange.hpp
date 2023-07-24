#ifndef __BITCOIN_EXCHANGE_HPP__
# define __BITCOIN_EXCHANGE_HPP__

# define _DEFAULT_DB_PATH "./data.csv"

# include <map>
# include <string>

class BitcoinExchange {
  public:
    /* Coplien's form */
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);
    ~BitcoinExchange();

    void loadDatabase();

    const std::map<std::string, double>& getDataBase() const;

  private:
    /* Private attributes */
    std::map<std::string, double> _map;

    /* Private member functions */
    static bool validateDate(const std::string&);

};

#endif
