Ahora es el momento de pasar a cosas más serias. Desarrollamos algo extraño.
El contenedor std::stack es muy bonito. Desafortunadamente, es uno de los únicos contenedores STL que NO es iterable. Eso es muy malo.
Pero ¿por qué aceptaríamos esto? Especialmente si podemos tomarnos la libertad de destruir la pila original para crear las características que faltan.
Para reparar esta injusticia, debes hacer que el contenedor std::stack sea iterable.
Escribe una clase MutantStack. Se implementará en términos de std::stack.
Ofrecerá todas sus funciones miembro, además de una característica adicional: iteradores.
Por supuesto, escribirá y entregará sus propias pruebas para asegurarse de que todo funcione como se espera.

Si lo ejecuta por primera vez con su MutantStack y una segunda vez reemplaza MutantStack con, por ejemplo, un std::list, las dos salidas deberían ser las mismas. Por supuesto, cuando pruebe otro contenedor, actualice el código siguiente con las funciones miembro correspondientes (push() puede convertirse en push_back()).