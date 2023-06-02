#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {

	private:
		static Contact c[8];
		static int cptr;
	
	public:
		int  get_cptr(void);
		void incr_cptr(void);
		Contact get_c(int n);
		void set_c(int n, Contact c);
		void add_contact();
		void display();
		void pfield(std::string);
};

#endif
