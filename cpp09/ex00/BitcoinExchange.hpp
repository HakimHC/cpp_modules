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

    void parseInputValues(std::string) const;

    const std::map<std::string, double>& getDataBase() const;

  private:
    /* Private attributes */
    std::map<std::string, double> _map;

    /* Private member functions */
    static bool                   validateDate(const std::string&);
    static std::string            getKey(std::string, char delimiter);
    static float                  getValue(std::string, char delimiter);

};

#endif
