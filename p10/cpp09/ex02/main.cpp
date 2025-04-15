#include "PmergeMe.hpp"

int     main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    PmergeMe        go;
    try
    {
        go.ft_sort(argv, argc);
    }
    catch (PmergeMe::echecException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}