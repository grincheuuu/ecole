#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

//polymorphise ad hoc , appeler aussi surcharge de fonction
//on peut avoir differentes definitions de fonction ayant le meme nom
// mais prenant des parametres differents
// sa marche sur toutes les fonctions

class Sample
{
    public:
        Sample(void);
        ~Sample(void);

        void    bar(char const c) const;
        void    bar(int const n) const;
        void    bar(float const x) const;
        void    bar(Sample const & i) const;
};

#endif