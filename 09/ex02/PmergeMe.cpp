#include "PmergeMe.hpp"

Element::~Element()
{
	_value = -1;
	_paired = NULL;
	_index = 0;
}

Element::Element(int value): _value(value)
{
	_paired = NULL;
	_index = 0;
}

Element::Element(int value, Element *paired): _value(value), _paired(paired), _index(0)
{
}

Element::Element(const Element &copy)
{
	this->_value = copy._value;
	this->_paired = copy._paired;
	this->_index = copy._index;
}

Element	&Element::operator=(const Element &src)
{
	this->_value = src._value;
	this->_paired = src._paired;
	this->_index = src._index;

	return *this;
}

int		Element::get_value()
{
	return _value;
}

size_t		Element::get_index()
{
	return _index;
}

void	Element::set_index(size_t index)
{
	this->_index = index;
}

void	Element::set_pair(Element *a, Element *b)
{
	a->_paired = b;
	b->_paired = a;
}

Element	*Element::get_pair()
{
	return _paired;
}
