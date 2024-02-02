#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    // Aumenta la capacidad del vector hasta 10 elementos
    v.reserve(10);

    std::cout << "Capacidad del vector: " << (v.size() + v.capacity()) << '\n';

    return 0;
}
