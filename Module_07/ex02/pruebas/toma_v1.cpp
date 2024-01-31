#include <iostream>

template <typename T, size_t N>
class Array
{
private:
    T elements[N];

public:
    // Constructor que acepta un array
    Array(const T (&arr)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            elements[i] = arr[i];
        }
    }

    // Operador de corchetes para acceder a los elementos
    T &operator[](size_t index)
    {
        if (index < N)
            return elements[index];
        else
        {
            // Manejar el índice fuera de rango según tus necesidades
            throw std::out_of_range("Index out of range");
        }
    }

    // Función para imprimir los elementos del array
    void print()
    {
        for (size_t i = 0; i < N; ++i)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[] = {1, 2, 3};
    Array<int, 3> num(arr); // Uso del constructor con un array

    // Acceder e imprimir los elementos
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

