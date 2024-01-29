#include <iostream>
#include <cstdlib>

int main()
{
    const char *str1 = "123.45";
    const char *str2 = "abc";

    char *endptr1;
    char *endptr2;

    double result1 = strtod(str1, &endptr1);
    double result2 = strtod(str2, &endptr2);

    if (endptr1 == str1)
    {
        std::cout << "No se pudo convertir la cadena \"" << str1 << "\" a double." << std::endl;
    }
    else
    {
        std::cout << "Conversión exitosa: " << result1 << std::endl;
    }

    if (endptr2 == str2)
    {
        std::cout << "No se pudo convertir la cadena \"" << str2 << "\" a double." << std::endl;
    }
    else
    {
        std::cout << "Conversión exitosa: " << result2 << std::endl;
    }

    return 0;
}
