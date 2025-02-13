#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	long long value;
	std::list<int> L;
	std::deque<int> D;

	if (argc < 2)
		throw (PmergeMe::InvalidArgumentsException());
	for (int i = 1; i < argc; i++)
	{
		value = std::atol(argv[i]);
		if (!value || value < -2147483648 || value > 2147483647)
			throw (PmergeMe::InvalidArgumentsException());
		L.push_back(static_cast<int>(value));
		D.push_back(static_cast<int>(value));
	}
	std::cout << std::endl << "Unsorted sequence: ";
	print_result(L);
	std::cout << std::endl;
	
	//Sorting with list
	clock_t start_1 = clock();
	sort_list(&L);
	clock_t end_1 = clock();
	double time_1 = static_cast<double>(end_1 - start_1)/CLOCKS_PER_SEC * 1000;
	
	//Sorting with deque
	clock_t start_2 = clock();
	sort_list(&L);
	clock_t end_2 = clock();
	double time_2 = static_cast<double>(end_2 - start_2)/CLOCKS_PER_SEC * 1000;
	
	//Printing result
	std::cout << "Sorted sequence: ";
	print_result(L);
	std::cout << std::endl;
	std::cout << "[LIST] Using a list container, the program took " << time_1 << " ms to sort the sequence\n" << std::endl;
	std::cout << "[DEQUE] Using a deque container, the program took " << time_2 << " ms to sort the sequence" << std::endl;

}

PmergeMe::~PmergeMe()
{
}



void PmergeMe::sort_list(std::list<int> *L)
{
	std::list<int> left;
	std::list<int> right;

	//Splitting the list recursively to sort each segment and minimize element comparisons
	std::list<int>::iterator it = L->begin();
	
	if (L->size() == 1)
		return ;
	for (size_t i = 0; i < L->size() / 2; i++)
	{
		left.push_back(*it);
		it++;
	}
	while (it != L->end())
	{
		right.push_back(*it);
		it++;
	}
	sort_list(&left);
	sort_list(&right);

	//Reassembling and sorting the original segment by comparing the already sorted left and right sub-segments
	std::list<int>::iterator	l = left.begin();
	std::list<int>::iterator	r = right.begin();
	std::list<int>::iterator	i = L->begin();
	static int po = 0;
	while ((l != left.end() || r != right.end()) && i != L->end())
	{
		if (r == right.end() || (l != left.end() && *l <= *r))
		{
			if (r != right.end())
				po++;
			*i = *l;
			l++;
		}
		else if (l == left.end() || (r != right.end() && *l > *r))
		{
			if (l != left.end())
				po++;
			*i = *r;
			r++;
		}
		i++;
	}
	std::cout << "HEREEEEEEEEEE : " << po << std::endl;
}

void	PmergeMe::sort_deque(std::deque<int> *D)
{
	std::deque<int> left;
	std::deque<int> right;

	//Splitting the deque recursively to sort each segment and minimize element comparisons

	if (D->size() == 1)
		return ;
	for (size_t i = 0; i < D->size() / 2; i++)
		left.push_back((*D)[i]);
	for (size_t i = D->size() / 2; i < D->size(); i++)
		right.push_back((*D)[i]);
	sort_deque(&left);
	sort_deque(&right);

	//Reassembling and sorting the original segment by comparing the already sorted left and right sub-segments
	size_t l = 0;
	size_t r = 0;
	size_t i = 0;

	while ((l < left.size() || r < right.size()) && i < D->size())
	{
		if (r == right.size() || (l == left.size() && left[l] <= right[r]))
		{
			(*D)[i] = left[l];
			l++;
		}
		else if (l == left.size() || (r == right.size() && left[l] > right[r]))
		{
			(*D)[i] = right[r];
			r++;
		}
		i++;
	}
}

void	PmergeMe::print_result(std::list<int> result)
{
	std::list<int>::iterator i = result.begin();
	
	while (i != result.end())
	{
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}