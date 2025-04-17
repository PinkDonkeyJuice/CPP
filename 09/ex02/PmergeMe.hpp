#pragma once

#include <iostream>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>

class	Element
{
	private:
		int	_value;
		Element	*_paired;
		size_t	_index;

	public:
		Element();
		Element(int value);
		Element(int value, Element *paired);
		Element(const Element &copy);
		~Element();

		Element	&operator=(const Element &src);

		int	get_value();
		size_t	get_index();
		void	set_index(size_t index);
		void	set_pair(Element *a, Element *b);
		Element	*get_pair();
		
};

template <typename Container>
class PmergeMe
{
	private:

	public:
		PmergeMe(int nval, char **input);
		~PmergeMe();

		void	sort(Container &L);
		void	print_result(Container result);
		void	binaryInsertion(Container &sorted, size_t max, Element *value);
		static std::vector<size_t> createJacobsthal(size_t length);
		Container make_pend(Container &L);

		void set_index_list(Container &L);

		Element *find_element(Container L, size_t index);
		//Exceptions
		class InvalidArgumentsException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Need a sequence of ints as arguments\n");
				}
		};
};

template <typename Container>
PmergeMe<Container>::PmergeMe(int nval, char **input)
{
	long long value;
	std::vector<Element> L;
	Container p_L;


	char	*endptr;
	for (int i = 1; i < nval; i++)
	{
		value = std::strtol(input[i], &endptr, 10);
		if (value < 0 || value > 2147483647)
		{
			for (typename Container::iterator it = p_L.begin(); it != p_L.end(); it++)
				delete (*it);
			throw (PmergeMe::InvalidArgumentsException());
		}
		p_L.push_back(new Element (value));
	}
	std::cout << std::endl << "Unsorted sequence: ";
	print_result(p_L);
	std::cout << std::endl;
	//Sorting with list
	clock_t start_1 = clock();
	sort(p_L);
	clock_t end_1 = clock();
	double time_1 = static_cast<double>(end_1 - start_1)/CLOCKS_PER_SEC * 1000;

	//Printing result
	std::cout << "Sorted sequence: ";
	print_result(p_L);
	std::cout << std::endl;
	std::cout << "The program took " << time_1 << " ms to sort the sequence\n" << std::endl;
	for (typename Container::iterator it = p_L.begin(); it != p_L.end(); it++)
		delete (*it);
	//std::cout << "[DEQUE] Using a deque container, the program took " << time_2 << " ms to sort the sequence" << std::endl;

}

template<typename Container>
PmergeMe<Container>::~PmergeMe()
{
}

template<typename Container>
void	PmergeMe<Container>::print_result(Container result)
{
	typename Container::iterator i = result.begin();
	
	while (i != result.end())
	{
		std::cout << (*i)->get_value() << " ";
		i++;
	}
	std::cout << std::endl;
}

template<typename Container>
void	PmergeMe<Container>::binaryInsertion(Container &sorted, size_t max, Element *value)
{
	typename Container::iterator low = sorted.begin();
	typename Container::iterator high = low;

	std::advance(high, max);

	while (low != high)
	{
		typename Container::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (value->get_value() < (*mid)->get_value())
			high = mid;
		else if (value->get_value() > (*mid)->get_value())
		{
			low = mid;
			low++;
		}
		else
		{
			sorted.insert(mid, value);
			value->set_index(std::distance(sorted.begin(), mid));
			return ;
		}
	}
	sorted.insert(low, value);
	value->set_index(std::distance(sorted.begin(), low));
}


template <typename Container>
void	PmergeMe<Container>::set_index_list(Container &L)
{
	for (typename Container::iterator it = L.begin(); it != L.end(); it++)
	{
		(*it)->set_index(std::distance(L.begin(), it));
	}
}


template <typename Container>
Element	*PmergeMe<Container>::find_element(Container L, size_t index)
{
	for (typename Container::iterator it = L.begin(); it != L.end(); it++)
	{
		if (((*it)->get_pair())->get_index() == index)
			return *it;
	}
	return *L.begin();
}

template<typename Container>
Container PmergeMe<Container>::make_pend(Container &L)
{
	Container pend;
	size_t i = 0;

	while (i < L.size())
	{
		Element *to_add(find_element(L, i));
		pend.push_back(to_add);
		i++;
	}
	return pend;
}

template<typename Container>
void PmergeMe<Container>::sort(Container &L)
{
	if (L.size() <= 1)
		return ;
	Container larger;
	Container smaller;
	Element *last = NULL;

	//Assigning the pairs together and seperating between the larger elements and the smaller
	for (typename Container::iterator it = L.begin(); it != L.end(); )
	{
		typename Container::iterator i_next = it;
		i_next++;

		if (i_next == L.end())
		{
			last = *it;
			break;
		}
		(*it)->set_pair(*it, *i_next);
		if ((*it)->get_value() >= (*i_next)->get_value())
		{
			larger.push_back(*it);
			smaller.push_back(*i_next);
		}
		else
		{
			larger.push_back(*i_next);
			smaller.push_back(*it);
		}
		std::advance(it, 2);
	}
	//Recursive sorting of the larger element. The element class lets us keep track of the pairs
	sort(larger);
	set_index_list(larger);
	
	//Order smaller into pend by the position of their pair
	Container pend = make_pend(smaller);
	if (!pend.empty())
	{
		larger.push_front(pend.front());
		pend.pop_front();
	}

	//Create Jacobsthal sequence to base indexes and insert remaining with binary insertion
	std::vector<size_t> jacobsthal;
	size_t 	j_index = 1;
	size_t	i_added = 0;

	jacobsthal.push_back(1);
	jacobsthal.push_back(3);
	while (i_added < pend.size())
	{
		size_t i_left = pend.size() - i_added;
		size_t group_size = jacobsthal[j_index] - jacobsthal[j_index - 1];
		if (pend.size() == 1)
		{
			binaryInsertion(larger, i_added + 2, pend.front());
			break ;
		}
		if (group_size > i_left)
			group_size = i_left;
		size_t index = group_size + i_added;
		size_t i_stop = i_added;
		while (i_added != i_stop + group_size)
		{
			typename Container::iterator it = pend.begin();
			set_index_list(larger);
			index--;
			std::advance(it, index);
			Element *to_insert = *it;
			size_t index_max;
			if (to_insert->get_pair() == NULL)
				index_max = larger.size() - 1;
			else
				index_max = (to_insert->get_pair())->get_index();
			binaryInsertion(larger, index_max, to_insert);
			i_added++;
		}
		jacobsthal.push_back(2 * jacobsthal[j_index - 1] + jacobsthal[j_index]);
		j_index++;
	}
	if (last != NULL && last->get_value() >= 0)	
		binaryInsertion(larger, larger.size(), last);
	L = larger;
}
