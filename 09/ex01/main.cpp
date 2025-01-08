#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Need exactly 1 argument: RPN expression" << std::endl;
        return 1;
    }
    try 
    {
        RPN calculator = RPN(argv[1]);

        calculator.calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}