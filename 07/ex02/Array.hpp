#pragma once
#include "cstdlib"
#include "iostream"

template<typename S>
class Array
{	
	private:
		unsigned int _size;
		S	*_array;
	public:
		Array(): _size(0)
		{
			std::cout << "Default constructor called for array of size 0" << std::endl;
			this->_array = new S[0];
		}
		Array(unsigned int n): _size(n)
		{
			std::cout << "Constructor called for array of size " << this->_size << std::endl;
			this->_array = new S[this->_size];
		}
		Array(const Array &ref): _size(ref._size)
		{
			std::cout << "Copy constructor called for array of size " << this->_size << std::endl;
			this->_array = NULL;
			*this = ref;
		}

		~Array()
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}

		//Overload operators
		Array	&operator=(const Array &ref)
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (ref._size != 0)
			{
				this->_size = ref.size();
				this->_array = new S[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = ref._array[i];
			}
			return (*this);
		}

		S	&operator[](unsigned int i)
		{
			if (i >= this->_size)
			{
				throw(IndexOutOfBoundsException());
			}
			return (this->_array[i]);
		}

		//Exceptions
		class IndexOutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		//Methods
		unsigned int	size() const
		{
			return (this->_size);
		}
};

template<typename S>
const char	*Array<S>::IndexOutOfBoundsException::what() const throw()
{
	return ("Error: Index is out of bounds\n");
}