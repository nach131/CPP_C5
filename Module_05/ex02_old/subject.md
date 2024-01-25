Capítulo V
Ejercicio 02: No, necesitas el formulario 28B,
no el 28C...
Ejercicio: 02
No, necesitas el formulario 28B, no el 28C...
Directorio de entrega: ex02/
Archivos para entregar: Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp],  
Bureaucrat.cpp +
AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], +
RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]
Funciones prohibidas: Ninguna
Ya que ahora tienes formularios básicos, es hora de hacer algunos más que realmente hagan algo.

En todos los casos, la clase base Form debe ser una clase abstracta, y por lo tanto debe 
renombrarse a AForm. Ten en cuenta que los atributos del formulario deben permanecer privados 
y que están en la clase base.

Agrega las siguientes clases concretas:

- ShrubberyCreationForm: Grados requeridos: firmar 145, ejecutar 137
Crea un archivo <objetivo>_shrubbery en el directorio de trabajo, y escribe árboles ASCII dentro de él.

- RobotomyRequestForm: Grados requeridos: firmar 72, ejecutar 45
Hace algunos ruidos de perforación. Luego, informa que <objetivo> ha sido robotomizado
exitosamente el 50% de las veces. De lo contrario, informa que la robotomía falló.

- PresidentialPardonForm: Grados requeridos: firmar 25, ejecutar 5  
Informa que <objetivo> ha sido indultado por Zaphod Beeblebrox.

Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por ejemplo, "casa" si quieres plantar arbustos en casa.

Ahora, agrega la función miembro execute(Bureaucrat const & executor) const a la clase base form e implementa una función para ejecutar la acción del formulario de las clases concretas. Debes verificar que el formulario esté firmado y que el grado del burócrata que intenta ejecutar el formulario sea lo suficientemente alto. De lo contrario, lanza una excepción apropiada.

Ya sea que desees verificar los requisitos en cada clase concreta o en la clase base (luego llamas a otra función para ejecutar el formulario) depende de ti. Sin embargo, una forma es más bonita que la otra.

Por último, agrega la función miembro executeForm(AForm const & form) al Bureaucrat. Debe intentar ejecutar el formulario. Si tiene éxito, imprime algo como:

<burócrata> ejecutó <formulario>  

Si no, imprime un mensaje de error explícito.

Implementa y entrega algunas pruebas para asegurarte de que todo funcione según lo esperado.

10

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