#include <iostream>
#include <cmath> // para usar nanf
// using namespace std;

int main()
{
	float a = std::numeric_limits<float>::quiet_NaN(); // -inff en C++98
	double b = nanf("nan");

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	return 0;
}
// ```
// El programa muestra el valor de las variables `a` y `b`. En C++98, la sintaxis correcta para obtener -infinity es usar la función `numeric_limits<float>::quiet_NaN()`, que devuelve el valor NaN (no un número) en lugar de -inf. Para obtener nanf, se utiliza la función `nanf("nan")`. La salida del programa sería:
// ```
// a: nan
// b: nan
// ```
// Ambas variables tienen el valor nan (no un número), que indica que no es un número válido.