

Capítulo VI  
Ejercicio 03: Al menos esto es mejor que hacer café

Ejercicio: 03
Al menos esto es mejor que hacer café

Directorio de entrega: ex03/

Archivos para entregar: Archivos de ejercicios anteriores + Intern.{h, hpp}, Intern.cpp

Funciones prohibidas: Ninguna

Debido a que llenar formularios es lo suficientemente molesto, sería cruel pedirle a nuestros burócratas que hagan esto todo el día. Afortunadamente, existen pasantes. En este ejercicio, debes implementar la clase Intern. El pasante no tiene nombre, grado, ni características únicas. Lo único que les importa a los burócratas es que hagan su trabajo.

Sin embargo, el pasante tiene una capacidad importante: la función makeForm(). Toma dos cadenas. El primero es el nombre de un formulario y el segundo es el objetivo del formulario. Devuelve un puntero a un objeto Form (cuyo nombre es el que se pasó como parámetro) cuyo objetivo se inicializará al segundo parámetro.

Imprimirá algo como:

Intern crea <formulario>

Si el nombre del formulario pasado como parámetro no existe, imprime un mensaje de error explícito.  

Debes evitar soluciones ilegibles y feas como usar un bosque de if/elseif/else. Este tipo de cosas no serán aceptadas durante el proceso de evaluación. Ya no estás en Piscine (piscina) anymore. Como de costumbre, debes probar que todo funciona según lo esperado.

Por ejemplo, el siguiente código crea un RobotomyRequestForm dirigido a "Bender":

{

Intern someRandomIntern;

Form* rrf;

rrf = someRandomIntern.makeForm("robotomy request", "Bender");

}

12