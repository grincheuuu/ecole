#include <iostream>
#include <fstream>

int main()
{
    std::ifstream   ifs("number"); // input file stream, on cree un stream d input et j'ouvre le fichier numbers
    unsigned int       dst;
    unsigned int       dst2;

    ifs >> dst >> dst2;

    std::cout << dst << " " << dst2 << std::endl;
    ifs.close(); //ferme le stream


    std::ofstream      ofs("test.txt"); // output filestream
    ofs << "i am " << std::endl;
    ofs.close();
    return 0;
}