#include <iostream>

// Define códigos de color si aún no están definidos
#define PINK "\033[95m"
#define GREEN "\033[92m"
#define RESET "\033[0m"

template <typename T, size_t N>
class Array
{
private:
    T _items[N];

public:
    Array(const T *values, size_t size);
    T &operator[](size_t index);
    size_t size() const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return "[ERROR] [Índice está fuera de límites]"; }
    } e_out;
};

template <typename T, size_t N>
Array<T, N>::Array(const T *values, size_t size)
{
    if (size != N)
    {
        throw e_out;
    }

    for (size_t i = 0; i < N; ++i)
    {
        _items[i] = values[i];
    }
}

template <typename T, size_t N>
T &Array<T, N>::operator[](size_t index)
{
    if (index >= N)
    {
        throw e_out;
    }
    return _items[index];
}

template <typename T, size_t N>
size_t Array<T, N>::size() const
{
    return N;
}

int main()
{
    {
        int values[] = {1, 2, 3};
        Array<int, 3> a(values, sizeof(values) / sizeof(values[0]));

        std::cout << "Array elements: ";
        for (size_t i = 0; i < a.size(); ++i)
        {
            std::cout << a[i] << ", ";
        }
    }
    {
        std::string values[] = {"uno", "dos", "tres"};
        Array<std::string, 3> a(values, sizeof(values) / sizeof(values[0]));

        std::cout << "Array elements: ";
        for (size_t i = 0; i < a.size(); ++i)
        {
            std::cout << a[i] << ", ";
        }
    }

    return 0;
}
