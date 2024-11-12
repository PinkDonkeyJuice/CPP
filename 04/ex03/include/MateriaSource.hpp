#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_source[4];
	public:
	    MateriaSource();
	    MateriaSource(const  MateriaSource &copy);
	    ~MateriaSource();

	    MateriaSource &operator=(const  MateriaSource &src);
		void	learnMateria(AMateria *m);
		AMateria *createMateria(const std::string &type);
};

#endif