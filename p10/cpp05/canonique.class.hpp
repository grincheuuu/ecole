#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream>

class Sample
{
    public:
        Sample(void); // constructeur par default
        Sample(int const n);
        Sample(Sample const & src); // constructeur par copie, nouvel instance creer
        ~Sample(void); // destructeur , rajouter virtual

        Sample &    operator=(Sample const & rhs); // operateur =

        int     getFoo(void) const;
    
    private:
        int     _foo;
};

std::ostream &    operator<<(std::ostream & o, Sample const & i);

#endif