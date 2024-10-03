#!/bin/bash
read name
majname=$(echo $name | tr 'a-z' 'A-Z')
echo "#ifndef $majname""_HPP" >> $name.hpp
echo "#define $majname""_HPP" >> $name.hpp
echo -e >> $name.hpp
echo "class $name" >> $name.hpp
echo "{" >> $name.hpp
echo "  public:" >> $name.hpp
echo "      $name();" >> $name.hpp
echo "      $name(const $name &cpy);" >> $name.hpp
echo "      $name   &operator=(const $name &cpy);" >> $name.hpp
echo "      ~$name();" >> $name.hpp
echo -e >> $name.hpp
echo "  private:" >> $name.hpp
echo -e >> $name.hpp
echo "};" >> $name.hpp
echo -e >> $name.hpp
echo "#endif" >> $name.hpp
echo "#include \"$name.hpp\"" >> $name.cpp
echo -e >> $name.cpp
echo "$name::$name()" >> $name.cpp
echo "{" >> $name.cpp
echo -e >> $name.cpp
echo "}" >> $name.cpp
echo -e >> $name.cpp
echo "$name::$name(const $name &cpy)" >> $name.cpp
echo "{" >> $name.cpp
echo "  *(this) = cpy;" >> $name.cpp
echo "}" >> $name.cpp
echo -e >> $name.cpp
echo "$name &$name::operator=(const $name &src)" >> $name.cpp
echo "{" >> $name.cpp
echo "  return (*this);" >> $name.cpp
echo "}" >> $name.cpp
echo -e >> $name.cpp
echo "$name::~$name()" >> $name.cpp
echo "{" >> $name.cpp
echo -e >> $name.cpp
echo "}" >> $name.cpp
echo -e >> $name.cpp
