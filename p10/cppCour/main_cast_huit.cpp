// seul cast qui peut faire un cast des qualifier de type = const
// const cast

int main(void)
{
    int   a = 42;

    int const *  b =&a; //implicit promotion = ok
//    int *       c = b; //                   implicit demotion = NO
    int *       d = const_cast<int *>(b); //explicit demotion = ok // entre chevron le type cible

    return (0);
}