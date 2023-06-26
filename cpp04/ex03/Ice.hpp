#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(Ice&);
		Ice& operator=(Ice&);
		~Ice();

		AMateria* clone() const;
};

#endif
