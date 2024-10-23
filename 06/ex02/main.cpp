#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


Base	*generate(void)
{
    std::srand(std::time(NULL));
    switch(std::rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void    identify(Base *p)
{
    if (p==NULL)
        std::cout << "NULL" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
    }
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
    }
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
    }
    std::cout << "Not a known class" << std::endl;
}

int main()
{
    Base *test = generate();
    std::cout << "Identify as a pointer" << std::endl;
    identify(test);
    std::cout << "Identify as a reference" << std::endl;
    identify (&(*test));
    delete(test);
}
