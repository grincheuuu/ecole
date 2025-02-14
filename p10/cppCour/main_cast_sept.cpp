// reinterprete cast = il permet de faire des reinterpretation , des upcast et des downcast
// c le plus permissif
// on peut reiterpreter nimporte quel adresse vers nimporte quel autre adresse
// tres souvent utiliser pour les retypages

int main(void)
{
    float   a = 420.42f;

    void *  b =&a; //implicit promotion = ok

    // il n'y a aucune verification danger
    int *   c = reinterpret_cast<int *>(b); // explicit demotion = ok
    int &   d = reinterpret_cast<int &>(b); // explicit demotion = ok

    return (0);
}