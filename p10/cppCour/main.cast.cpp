
void    dump_32bits_integer(int const n);
void    dump_64bits_double(double const z);

int main(void)
{
    int a = 42; // 32 bit 4octet

    double  b = a; // implicite cast double 64bits
    double  c = (double)a; // explicit cast

    double d = a; // implicit promotion -> ok
    //flag de gcc pour les convertion implicite
    //-wno-conversion

//on passse d'un type plus precis, float double, vers un type moin precis , danger
    int     e = d; // implicit demotion -> aleatoire
    int     f = (int)d; // explicit demotion -> ok // a utiliser si la perte de precision est pas grave

    dump_32bits_integer(a);

    dump_64bits_double(b);
    dump_64bits_double(c);

    dump_64bits_double(d);
    dump_32bits_integer(e);
    dump_32bits_integer(f);
    return (0);
}