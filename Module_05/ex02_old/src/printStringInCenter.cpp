#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

// // Función para obtener el ancho de la ventana de la terminal
// int getTerminalWidth()
// {
// 	return system("tput cols");
// }

int getTerminalWidth()
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size.ws_col;
}

// Función para imprimir la cadena en el centro de la terminal
void printStringInCenter(const std::string &str)
{
	int terminalWidth = getTerminalWidth();

	std::cout << terminalWidth << std::endl;
	// Calcular la posición para imprimir en el centro
	int padding = (terminalWidth - str.length()) / 2;

	// Imprimir espacios en blanco para centrar la cadena
	for (int i = 0; i < padding; ++i)
		std::cout << "▄";

	// Imprimir la cadena en el centro
	std::cout << str;

	// Imprimir espacios en blanco después de la cadena hasta el final de la columna
	for (int i = padding + str.length(); i < terminalWidth; ++i)
		std::cout << "▄";

	std::cout << std::endl;
}

int main()
{
	std::string str = "[ 42 Barcelona ]";

	// Imprimir la cadena en el centro de la terminal
	printStringInCenter(str);

	return 0;
}
