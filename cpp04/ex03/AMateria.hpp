#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>

# define MAXPTR 1024

enum state {
	UNEQUIPPED,
	EQUIPPED
};

class ICharacter;

class AMateria {

	protected:
		std::string const 	_type;
		bool			_state;
	
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria&);
		AMateria& operator=(AMateria&);
		virtual ~AMateria();

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		void		setState(bool state);
		bool		getState() const;
};

#endif
