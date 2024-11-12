#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL)
			delete (this->_source[i]);
	}
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	std::cout << "Materia source copy constructor called" << std::endl;
    *this = ref;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (ref._source[i])
			delete this->_source[i];
		if (ref._source[i] == NULL)
			this->_source[i] = NULL;
		else
			this->_source[i] = ref._source[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	while (i < 4 && this->_source[i] != NULL)
		i++;
	if (i != 4)
	{
		std::cout << "Added " << m->getType() << " to materia source" << std::endl;
		this->_source[i] = m;
	}
	else
	{
		std::cout << "Can't learn any new materia" << std::endl;
		delete m;
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL && this->_source[i]->getType() == type)
		{
			std::cout << "Created a " << type << " materia" << std::endl;
			return (this->_source[i]->clone());
		}
	}
	std::cout << "In order to create requested materia, "<< type << " needs to be learned first" << std::endl;
	return NULL;
}
