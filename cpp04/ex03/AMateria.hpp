#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>

class ICharacter;

class AMateria {

	protected:
		std::string const _type;
	
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria&);
		AMateria& operator=(AMateria&);
		virtual ~AMateria();

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
