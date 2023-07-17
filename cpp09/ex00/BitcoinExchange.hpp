#ifndef __BITCOIN_EXCHANGE_HPP
# define __BITCOIN_EXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		static void 	csvParser(std::string&);
		void 		loadDatabase();

	private:
		std::map<std::string, float> 	_mapDatabase;
		std::map<std::string, float> 	_mapInFile;

};

#endif
