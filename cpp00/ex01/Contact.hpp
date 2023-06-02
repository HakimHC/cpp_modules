#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {

	private:
		std::string fn;
		std::string ln;
		std::string nn;
		std::string pn;
		std::string ds;
		int populated;

	public:
		std::string get_fn(void);
		std::string get_ln(void);
		std::string get_nn(void);
		std::string get_pn(void);
		std::string get_ds(void);

		void set_fn(std::string);
		void set_ln(std::string);
		void set_nn(std::string);
		void set_pn(std::string);
		void set_ds(std::string);
		void set_p(int);
		int exists();
};

#endif
