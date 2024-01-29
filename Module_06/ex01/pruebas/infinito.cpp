
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Uso: " << argv[0] << " entrada1" << std::endl;
        return 1;
    }

    char *endptr;
    double result = strtod(argv[1], &endptr);

    // Comprobar si hubo algún error en la conversión
    if (*endptr != '\0')
    {
        std::cout << "Error en la conversión a double." << std::endl;
        return 1;
    }

    // Comprobar si el resultado es cero
    if (result == 0.0)
    {
        std::cout << "El argumento es cero." << std::endl;
    }
    // Comprobar si el resultado es infinito
    else if (std::isinf(result))
    {
        std::cout << "El argumento es infinito." << std::endl;
    }
    // Comprobar si el resultado contiene solo ceros
    else if (std::strchr(argv[1], '0') != nullptr)
    {
        std::cout << "El argumento contiene ceros." << std::endl;
    }
    // Comprobar si el resultado es NaN
    else if (std::isnan(result))
    {
        std::cout << "El argumento es NaN." << std::endl;
    }
    // Ninguna de las condiciones anteriores se cumplió
    else
    {
        std::cout << "Ninguna condición se cumplió." << std::endl;
    }

    return 0;
}
