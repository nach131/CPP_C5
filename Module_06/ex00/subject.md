 Aquí está la traducción al español del documento:

C++ - Módulo 05
Repetición y excepciones

Resumen:
Este documento contiene los ejercicios del Módulo 05 de los módulos de C++.
Versión: 10.1

Contenido
I Introducción 2  
II Reglas generales 3
III Ejercicio 00: ¡Mamá, cuando sea grande quiero ser burócrata! 5
IV Ejercicio 01: ¡En formación, gusanos! 7   
V Ejercicio 02: No, necesitas el formulario 28B, no el 28C... 9
VI Ejercicio 03: Al menos esto es mejor que preparar café 11
VII Entrega y evaluación por pares 13

1

Capítulo I
Introducción
C++ es un lenguaje de programación de propósito general creado por Bjarne Stroustrup como una extensión del lenguaje de programación C, o "C con Clases" (fuente: Wikipedia).
  
El objetivo de estos módulos es introducirte a la Programación Orientada a Objetos. Este será el punto de partida de tu viaje en C++. Se recomiendan muchos lenguajes para aprender POO. Decidimos elegir C++ ya que se deriva de tu viejo amigo C.
  
Debido a que este es un lenguaje complejo, y para mantener las cosas simples, tu código cumplirá con el estándar C++98.
  
Somos conscientes de que el C++ moderno es muy diferente en muchos aspectos. Así que si quieres convertirte en un desarrollador de C++ competente, depende de ti ir más allá después del Common Core 42!

2

Capítulo II 
Reglas generales

Compilación
- Compila tu código con c++ y las banderas -Wall -Wextra -Werror
- Tu código debería compilar aún si agregas la bandera -std=c++98

Convenciones de formato y nomenclatura
- Los directorios de los ejercicios se nombrarán de esta forma: ex00, ex01, ..., exn
- Nombra tus archivos, clases, funciones, funciones miembro y atributos como se requiere en las pautas.
- Escribe los nombres de las clases en formato UpperCamelCase. Los archivos que contienen el código de la clase siempre se nombrarán de acuerdo al nombre de la clase. Por ejemplo:
ClassName.hpp/ClassName.h, ClassName.cpp o ClassName.tpp. Entonces, si tienes un archivo de encabezado que contiene la definición de una clase "BrickWall" que representa una pared de ladrillos, su nombre será BrickWall.hpp.
- A menos que se especifique lo contrario, todos los mensajes de salida deben terminar con un carácter de nueva línea y mostrarse en la salida estándar.
- ¡Adiós Norminette! No se aplica ningún estilo de codificación en los módulos de C++. Puedes seguir el que más te guste. Pero ten en cuenta que un código que tus evaluadores de pares no puedan entender es un código que no pueden calificar. Haz tu mejor esfuerzo para escribir un código limpio y legible.

Permitido/Prohibido
Ya no estás programando en C. ¡Es hora de C++! Por lo tanto:

- Se permite usar casi todo de la biblioteca estándar. Por lo tanto, en lugar de apegarte a lo que ya conoces, sería inteligente usar tanto como sea posible las versiones de C++ de las funciones de C a las que estás acostumbrado.

- Sin embargo, no puedes usar ninguna otra biblioteca externa. Esto significa que las bibliotecas C++11 (y derivadas) y Boost están prohibidas. Las siguientes funciones también están prohibidas: *printf(), *alloc() y free(). Si las usas, tu calificación será 0 y eso es todo.

- Ten en cuenta que a menos que se indique explícitamente lo contrario, las palabras clave using namespace <ns_name> y friend están prohibidas. De lo contrario, tu calificación será -42.

- Se permite usar STL solo en los Módulos 08 y 09. Eso significa: no Contenedores (vector/list/map/etc) y no Algoritmos (todo lo que requiera incluir el encabezado <algorithm>) hasta entonces. De lo contrario, tu calificación será -42.

Algunos requisitos de diseño
- Las fugas de memoria también ocurren en C++. Cuando asignas memoria (usando la palabra clave new), debes evitar fugas de memoria.

- Desde el Módulo 02 al Módulo 09, tus clases deben estar diseñadas en la Forma Canónica Ortodoxa, excepto cuando se indique explícitamente lo contrario. 

- Cualquier implementación de función puesta en un archivo de encabezado (excepto las plantillas de función) significa 0 en el ejercicio.

- Debes poder usar cada uno de tus encabezados de forma independiente de los demás. Por lo tanto, deben incluir todas las dependencias que necesitan. Sin embargo, debes evitar el problema de la inclusión doble agregando protecciones de inclusión. De lo contrario, tu calificación será 0.

Léame
- Puedes agregar algunos archivos adicionales si los necesitas (es decir, para dividir tu código). Como estas tareas no son verificadas por un programa, no dudes en hacerlo siempre y cuando entregues los archivos obligatorios.

- A veces, las pautas de un ejercicio parecen cortas pero los ejemplos pueden mostrar requisitos que no están escritos explícitamente en las instrucciones.

- ¡Lee cada módulo completamente antes de comenzar! En serio, hazlo.

- ¡Por Odín, por Thor! ¡Usa tu cerebro!

Tendrás que implementar muchas clases. Esto puede parecer tedioso, a menos que seas capaz de scriptar tu editor de texto favorito.

Se te da cierta libertad para completar los ejercicios. Sin embargo, sigue las reglas obligatorias y no seas perezoso. Te perderías mucha información útil. No dudes en leer sobre conceptos teóricos.


Capítulo III
Ejercicio 00: ¡Mamá, cuando sea grande, quiero ser burócrata!
Ejercicio: 00
¡Mamá, cuando sea grande, quiero ser burócrata!
Directorio de entrega: ex00/
Archivos para entregar: Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
Funciones prohibidas: Ninguna
Tenga en cuenta que las clases de excepción no tienen que estar diseñadas en 
Forma Canónica Ortodoxa. Pero todas las demás clases tienen que estarlo.

Diseñemos una pesadilla artificial de oficinas, pasillos, formularios y colas de espera.
¿Suena divertido? ¿No? Qué mal.

Primero, comencemos con el engranaje más pequeño de esta vasta máquina burocrática: el Burócrata.
Un Burócrata debe tener:
- Un nombre constante.
- Y un grado que va desde 1 (el grado más alto posible) hasta 150 (el grado más bajo posible).

Cualquier intento de instanciar un Burócrata usando un grado no válido debe arrojar una excepción:
ya sea Bureaucrat::GradeTooHighException o Bureaucrat::GradeTooLowException.

Proporcionarás getters para ambos atributos: getName() y getGrade(). Implementa también dos funciones miembro para incrementar o disminuir el grado del burócrata. Si el grado está fuera de rango, ambos arrojarán las mismas excepciones que el constructor.

Recuerda. Dado que el grado 1 es el más alto y 150 el más bajo,
incrementar un grado 3 debería dar un grado 2 al burócrata.

Las excepciones arrojadas deben poder capturarse utilizando bloques try y catch:

try
{
/* haz algunas cosas con burócratas */ 
}
catch (std::exception & e)
{
/* maneja la excepción */
}

Implementarás una sobrecarga del operador de inserción («) para imprimir algo como
(sin los corchetes angulares):

<nombre>, burócrata grado <grado>.

Como de costumbre, entrega algunas pruebas para demostrar que todo funciona según lo esperado.

6

Capítulo IV
Ejercicio 01: ¡En formación, gusanos!

Ejercicio: 01
¡En formación, gusanos!

Directorio de entrega: ex01/
Archivos para entregar: Archivos del ejercicio anterior + Form.{h, hpp}, Form.cpp
Funciones prohibidas: Ninguna

Ahora que tienes burócratas, démosles algo que hacer. ¿Qué mejor actividad podría haber que la de llenar una pila de formularios?

Entonces, hagamos una clase Formulario. Tiene:

- Un nombre constante.
- Un booleano que indica si está firmado (al construirlo, no lo está).
- Un grado constante requerido para firmarlo. 
- Y un grado constante requerido para ejecutarlo.

Todos estos atributos son privados, no protegidos.

Los grados del Formulario siguen las mismas reglas que se aplican al Burócrata. Por lo tanto, se arrojarán las siguientes excepciones si un grado del formulario está fuera de rango:

Form::GradeTooHighException y Form::GradeTooLowException.

Al igual que antes, escribe getters para todos los atributos y una sobrecarga del operador de inserción («) que imprima toda la información del formulario.

Agrega también una función miembro beSigned() al Formulario que toma un Burócrata como parámetro. Cambia el estado del formulario a firmado si el grado del burócrata es lo suficientemente alto (más alto o igual al requerido). Recuerda, el grado 1 es más alto que el grado 2.

Si el grado es demasiado bajo, arroja un Form::GradeTooLowException.

Por último, agrega una función miembro signForm() al Burócrata. Si el formulario se firmó, imprimirá algo como:

<burócrata> firmó <formulario>

De lo contrario, imprimirá algo como:

<burócrata> no pudo firmar <formulario> porque <razón>.

Implementa y entrega algunas pruebas para asegurarte de que todo funcione según lo esperado.

8

 Aquí está la traducción al castellano del documento en inglés:

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