#include <iostream>
#include "ph2.class.hpp"

Sample::Sample(void)
{
    std::cout << " Constructor called " << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << " Destructeur called" << std::endl;
    return;
}

void    Sample::bar(char const c) const
{
    std::cout << "c" << c << std::endl;
    return;
}

void    Sample::bar(int const n) const
{
    std::cout << "n" << n << std::endl;
    return;
}

void    Sample::bar(float const x) const
{
    std::cout << "x" << x << std::endl;
    return;
}

void    Sample::bar(Sample const & i) const
{
    (void)i;
    std::cout << "sample const & i" << std::endl;
    return;
}