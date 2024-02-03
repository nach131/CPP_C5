Desarrolle una clase Span que pueda almacenar un máximo de N enteros. N es una variable int sin signo y será el único parámetro pasado al constructor.
Esta clase tendrá una función miembro llamada addNumber() para agregar un solo número al Span. Se utilizará para rellenarlo. Cualquier intento de agregar un nuevo elemento si ya hay N elementos almacenados debería generar una excepción.
A continuación, implemente dos funciones miembro: shortSpan() y longSpan()
Descubrirán, respectivamente, el intervalo más corto o el intervalo más largo (o la distancia, si lo prefiere) entre todos los números almacenados y lo devolverán. Si no hay números almacenados, o solo uno, no se podrá encontrar ningún intervalo. Por lo tanto, lanza una excepción.
Por supuesto, escribirás tus propias pruebas y serán mucho más exhaustivas que las siguientes. Pruebe su Span al menos con un mínimo de 10 000 números. Más sería aún mejor.