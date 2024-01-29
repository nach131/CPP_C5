#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>  // Necesario para usar INFINITY y isnan

void convertLiteral(const std::string &literal)
{
    // Intentar convertir el literal a char
    char charValue;
    std::istringstream charStream(literal);
    if (charStream >> charValue && charStream.eof())
    {
        if (std::isprint(charValue))
        {
            std::cout << "char: '" << charValue << "'" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    // Intentar convertir el literal a int
    int intValue;
    std::istringstream intStream(literal);
    if (intStream >> intValue && intStream.eof())
    {
        std::cout << "int: " << intValue << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }

    // Intentar convertir el literal a float
    float floatValue;
    std::istringstream floatStream(literal);
    if (floatStream >> floatValue && floatStream.eof())
    {
        std::cout << "float: " << floatValue << "f" << std::endl;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "float: " << literal << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
    }

    // Intentar convertir el literal a double
    double doubleValue;
    std::istringstream doubleStream(literal);
    if (doubleStream >> doubleValue && doubleStream.eof())
    {
        std::cout << "double: " << doubleValue << std::endl;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "double: " << literal << std::endl;
    }
    else
    {
        std::cout << "double: impossible" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    convertLiteral(literal);

    return 0;
}

