#ifndef HARL_H
#define HARL_H

#include <string>


enum level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNDEFINED
};


class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		level lvl;

	public:
		Harl();
		~Harl();

		void complain(std::string level);
		void set_level(level lvl);
		level get_level(void);
};

level convert_str(std::string s);

#endif
