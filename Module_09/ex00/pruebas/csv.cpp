#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

void readCSV(const std::string &filename, std::map<std::string, std::string> &data)
{
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error al abrir el archivo " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, value;
		std::getline(iss, date, ',');
		std::getline(iss, value, ',');

		// Insertamos los datos en el mapa
		data[date] = value;
	}

	file.close();
}

int main()
{
	std::map<std::string, std::string> data;
	readCSV("data.csv", data);

	// Mostramos los datos almacenados en el mapa
	std::map<std::string, std::string>::iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		std::cout << "Fecha: " << it->first << ", Valor: " << it->second << std::endl;
	}

	return 0;
}
