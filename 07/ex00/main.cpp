#include <iostream>
#include "templates.hpp"

int	main(void)
{
	int ia = 10;
	int ib = 18;

	std::string sa = "Yo";
	std::string sb = "Salut";

	std::cout << min(ia, ib) << std::endl;
	std::cout << max(ia, ib) << std::endl;
	swap(ia, ib);
	std::cout << ia << std::endl;
	std::cout << ib << std::endl;

	std::cout << ::min(sa, sb) << std::endl;
	std::cout << ::max(sa, sb) << std::endl;
	swap(sa, sb);
	std::cout << sa << std::endl;
	std::cout << sb << std::endl;
}