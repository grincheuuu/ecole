#include "PmergeMe.hpp"

int     main(int argc, char **argv)
{
    std::vector<unsigned int>   ti;
    if (argc == 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        if (PmergeMe::ft_unsigned_int(argv[i]) == 1)
        {
            ti.clear();
            return (1);
        }
        ti.push_back(strtoul(argv[i], NULL, 0));
    }
    PmergeMe::ft_sort_un(ti);
//    ti.clear();
    return (0);
}