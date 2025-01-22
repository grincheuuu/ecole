/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:02:21 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:02:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
//    std::ofstream    era("aab.replace");
//    era.close();

    if (argc != 4)
    {
        std::cout << "this programme take 3 arguments : filename, string1, string2" << std::endl;
        return (1);
    }
    std::ifstream    ifs(argv[1]);
    if (!ifs)
    {
        std::cout << "open file in lecture error" << std::endl;
        return (1);
    }

    std::string out = std::string(argv[1]) + ".replace";
    std::ofstream    ofs(out.c_str(), std::ofstream::app);
    if (!ofs)
    {
        std::cout << "openfile in ecriture error" << std::endl;
        return (1);
    }

    std::string str;
    std::string content;
    int g = 0;
    while (std::getline(ifs, str))
    {
        if (g != 0)
         content += '\n';
        content += str;
        g++;
    }
    ifs.close();

    size_t  n;
    size_t  len = content.size();
    std::string contentDeux;
    size_t  temp = 0;
    if (std::string(argv[2]).empty())
    {
        ofs << content << std::endl;
        return (0);
    }
    size_t  s1l = std::string(argv[2]).size();

    n = content.find(std::string(argv[2]));
    contentDeux = content.substr(0, n);
    if (n < len)
         contentDeux += std::string(argv[3]);

    while (n < len)
    {
        temp = n + s1l;
        n = content.find(std::string(argv[2]), temp);
        contentDeux += content.substr(temp, n - temp);
        if (n < len)
            contentDeux += std::string(argv[3]);
    }

    ofs << contentDeux << std::endl;
    return 0;
}
