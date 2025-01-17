#include "ph2.class.hpp"

int main()
{
    Sample  a1;

    a1.bar('a');
    a1.bar(2);
    a1.bar(4.5f);
    a1.bar(a1);
    return 0;
}