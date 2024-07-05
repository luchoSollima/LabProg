## APUNTES

### CLASE 12/04/2024

Utilizar Pragma y/o if(ndef).   INVESTIGARLOS

### CLASE 26/04/2024

TP4: Ahora se arranca el tema arrays. Juego a realizar: "Mastermind".

```bash
Devoluciones tp2:

Poner comentarios en el codigo.
Inciializar todas las variables.
Espaciar un poco mas el codigo para la legibilidad.
Habia un bug porque me olvide de escribir un break. Testear más rigurosamente.
Revisar la posiblidad de clearear la pantalla cuando termina la ronda.
El .cpp se debe llamar main.cpp.

El resto bien, logica correcta.
```

Aprovechar el enum casteandolo a int, antes del switch.

TP3: Falta checkear condiciones para ganar y corroborar que el turno de cada jugador termina cuando debe (ejemplo, si sacas 1 en el dado termina tu turno. Revisarlo con el reglamento del juego.)

### CLASE 03/05/2024

Para el tp5, no usar arrays bidimensionales. No conviene.

17/5 Parcial.

TP1, TP2 no tienen nota numérica.

### CLASE 10/05/2024

No hay que olvidar la autoevaluación.

TP5: Un array por cada fila.

Nonograma: https://es.goobix.com/juegos-en-linea/nonogramas/?s=5

Hacerlo secuencialmente, ejemplo: patron 1 2: Pintas la primera casilla, dejas un espacio, y pintas dos casillas. El resto vacío. Asi para cada fila.

Sumatoria del patron Y los espacios vacios tiene que dar 15. La sumatoria correcta seria los numeros, mas 1 por cada uno (representando el espacio vacío que le sigue).

También dejarle al usuario no completar la fila si no desea, mas alla de los casos donde no se puede.

### CLASE 17/05/2024

Material en BlackBoard, Do(s) y Don't(s).

```bash
Devoluciones tp4 (3):

Poner comentarios arriba del codigo, no al costado.
Se pueden repetir colores, se puede dar un feedback incompleto ("OOO") o un feedback incorrecto ("a") y el juego sigue. Tambien se puede ingresar cualquier numero, no solo un numero de cuatro digitos para el codigo de colores.
La forma de tomar el input del usuario es inusual pero valida. Recomnedado: step by step, numero por numero.
Faltaba la condicion minima de jugar contra la maquina (esto lo termino desaprobando).
colorCodeInput no se compara en ningun momento, el juego depende más de lo que debería de los jugadores.
No utilizo el enum (porque el switch esta casteando).
Hay Spanglish entre las variables, los comentarios y el enum. Todo inglés la próxima. Por ejemplo, limArray seria arrayLimit.
Y claro, falta la autoevaluación.

El codigo esta bien en si y la presentiacion también.
```

### CLASE 31/05/2024

Buffer: cuando haces un input con cin, cada espacio que separa palabras o caracteres los guarda en el buffer, y podria saltarse cin futuros. Hay que limpiar el buffer para evitar bugs. Se pueden utilizar las siguientes funciones:

```bash
cin.ignore(10000);
cin.ignore(10000, '\n');
```

### CLASE 14/06/2024

```bash
Devoluciones tp5:

```

TP7, entrega el 5/7 y el 12/7, es la clase de recuperacion.

Reentrega de trabajos desaprobados y devolucion en el momento.

En los archivos .cpp va a haber **implementaciones/definiciones**. Si es main.cpp, va a estar el main. Si se llama player.cpp, estaran las funciones del player.
En los archivos .h, se hacen las declaraciones (excepto el main, que es el punto de entrada, por donde arranca a ejecutarse el programa).

Las funciones cada una tienen firma, para identificarlas inequivocamente.

Los archivos .h incluyen a los cpp, por eso cuando incluis un .h (por ejemplo, math.h) te dan funciones que funcionan.

Error **Unresolved external symbol**, el 99% de los casos es que una firma que no tiene definicion, o una definicion que no tiene firma.

### CLASE 05/07/2024

```bash
Devoluciones tp6:

Esta bien la entrega y el tp dentro de todo, prolijo. Lo mas grave es el tema de que despues de jugar una partida, no podes jugar otra. Te corta en el primer turno.
El otro problema es que hay muchas funciones parecida, en ese caso habria que usar loops, como un for.
Podria haber más comentarios.
Habia separación de archivos y no habia que hacerlo.
Aprobado con 4.

```
