#include <iostream>
#include <sstream>
#include <limits>

// Función para convertir a char
void convertToChar(const std::string& literal) {
    char charValue;
    std::istringstream stream(literal);
    
    if (stream >> charValue && stream.eof() && std::isprint(charValue)) {
        std::cout << "char: '" << charValue << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

// Función para convertir a int
void convertToInt(const std::string& literal) {
    int intValue;
    std::istringstream stream(literal);

    if (stream >> intValue && stream.eof()) {
        std::cout << "int: " << intValue << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
}

// Función para convertir a float
void convertToFloat(const std::string& literal) {
    float floatValue;
    std::istringstream stream(literal);

    if (stream >> floatValue && stream.eof()) {
        std::cout << "float: " << floatValue << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }
}

// Función para convertir a double
void convertToDouble(const std::string& literal) {
    double doubleValue;
    std::istringstream stream(literal);

    if (stream >> doubleValue && stream.eof()) {
        std::cout << "double: " << doubleValue << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];

    // Llamar a las funciones de conversión
    convertToChar(literal);
    convertToInt(literal);
    convertToFloat(literal);
    convertToDouble(literal);

    return 0;
}

