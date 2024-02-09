Tienes que crear un programa que genere el valor de una determinada cantidad de bitcoins en una fecha determinada.
Este programa debe utilizar una base de datos en formato csv que representará el precio de bitcoin a lo largo del tiempo. Esta base de datos se proporciona con este tema.
El programa tomará como entrada una segunda base de datos, almacenando los diferentes precios/fechas a evaluar.
Su programa debe respetar estas reglas:
• El nombre del programa es btc.
• Su programa debe tomar un archivo como argumento.
• Cada línea de este archivo debe utilizar el siguiente formato: "fecha | valor".
• Una fecha válida siempre tendrá el siguiente formato: Año-Mes-Día.
• Un valor válido debe ser un número flotante o un entero positivo, entre 0 y 1000.

Debe utilizar al menos un contenedor en su código para validar este ejercicio. Debe gestionar los posibles errores con un mensaje de error adecuado.

Si la fecha utilizada en la entrada no existe en su base de datos, entonces
deberá utilizar la fecha más cercana contenida en su BD. Tenga cuidado de utilizar la fecha inferior y no la superior.