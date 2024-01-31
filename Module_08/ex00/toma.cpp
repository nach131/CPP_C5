#include <iostream>
#include <map>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::map<int, int> numbers;

    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        numbers[i] = i;

    int target = 3;
    bool found = false;

    // Búsqueda manual en el mapa
    for (std::map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        if (it->second == target)
        {
            found = true;
            break;
        }
    }

    if (found)
        std::cout << "Value " << target << " exists in the map." << std::endl;
    else
        std::cout << "Value " << target << " doesn't exist in the map." << std::endl;

    return 0;
}
