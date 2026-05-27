# Bitácora de uso de IA — EcoMision

## ¿Para qué se uso la IA generativa?

Usamos la IA principalmente como herramienta de consulta y verificacion durante el
desarrollo de nuestro proyecto. La usamos para cuatro cosas concretas: reorganizar
un poco el enunciado para abstraer de manera mas sencilla las relaciones y las clases del sistema antes de empezar a programar,
consultar dudas puntuales sobre sintaxis de C++ y fallos de compilación, revisar
decisiones de diseño cuando no teniamos claro cual era la mejor opcion entre varias
alternativas y mejorar un poco o de alguna manera concretar los textos en los documentos solicitados como el readme.md o diseño.md

## ¿Qué decisión de diseño revisamos con IA?

La decision mas importante que revisamos fue como recorrer el unordered_map de
Reserva sin usar auto ni iteradores que no hubieramos empleado previamente en clase.
necesitabamos un unordered_map porque la instrucción lo pedía explicitamente para
buscar zonas por codigo, pero recorrerlo con un for clasico no es directo.

Le preguntamos a la IA como resolver ese problema y nos explico que una forma simple
era mantener un vector de datos de tipo string paralelo con los codigos en el orden en que se
agregan. De esta manera Reserva tiene dos estructuras: el unordered_map para buscar rapido por
codigo, y el vector codigos para recorrer con un for clasico. Eso nos permitio usar
solo lo que habiamos visto en el curso.

Tambien revisamos con IA la estructura de la clase abstracta ElementoInteractivo.
Teniamos claro que necesitabamos el metodo virtual puro interactuar(), pero no
estabamos seguros de si era necesario agregar mas metodos virtuales. La IA nos
explico que si Zona necesitaba mostrar el tipo y el efecto de cada elemento sin
saber cual subclase era, lo correcto era definir esos metodos en la clase base.
Eso nos llevo a agregar getTipo(), getEfecto() y fueUsado() como virtuales puros.

## ¿Qué sugerencias de IA aceptamos y por qué?

Aceptamos la sugerencia del vector de codigos paralelo en la clase Reserva porque resuelve
el problema que teniamos con estructuras sencillas y que conocemos: vector y for clasico. No agrega
complejidad innecesaria y es facil de explicar: cada vez que se agrega una zona
al mapa, tambien se guarda su codigo en el vector. Para buscar se usa el mapa y
para recorrer se usa el vector.

Aceptamos agregar getTipo(), getEfecto() y fueUsado() a ElementoInteractivo porque
era necesario para la correcta implementación del polimorfismo. Zona::mostrarElementos() necesita
imprimir el nombre, el tipo y el efecto de cada elemento. Si esos metodos no
estuvieran en la clase base, Zona tendria que saber que subclase es cada elemento
para poder llamar el metodo correcto, lo que romperia el polimorfismo. Con esos
metodos establecidos , Zona simplemente llama elementos[i]->getTipo() y funciona para
cualquier subclase sin ningun cambio.

## ¿Qué sugerencias de IA rechazamos o corregimos y por qué?

La IA sugirio en varias ocasiones usar getline para leer la entrada del usuario,
argumentando que permitiria nombres de elementos con espacios. Lo rechazamos porque
a pesar de que en algún momento se llegó a mencionar el comando, no lo hemos usado en el curso y preferiamos mantener todo tan simple como fuera posible.
En cambio adaptamos los nombres de los elementos para que fueran una sola palabra
(Venado, Plastico, PortalAlRio) y usamos cin >> que hemos utilizado mucho a lo largo del curso.

La IA tambien sugirio usar auto en los for que recorren el unordered_map, lo cual
hace el codigo mas corto. Lo rechazamos por la misma razon: auto se llegó a mencionar pero no se utilizó en las implementaciones previas. 
Preferimos escribir el tipo explicito aunque sea
mas largo, porque lo entendemos completamente.

En un momento la IA propuso usar unique_ptr para manejar la memoria automaticamente.
Lo rechazamos porque los smart pointers no hacen parte del curso y habria sido
codigo que no podriamos sustentar. Decidimos manejar la memoria manualmente con
destructores en Reserva y Zona como lo hemos hecho hasta este punto.

## ¿Qué parte del proyecto defiende cada integrante?

### Juan Guillermo Espinoza
Juan Guillermo se encargo del nucleo estructural del sistema: las clases EcoMision,
Reserva y Zona. Debe poder explicar y defender:

- Por que Reserva usa unordered_map y para que sirve el vector codigos paralelo.
- Como funciona el destructor de Reserva y por que es necesario.
- La sobrecarga de interactuar() en Zona: que es la sobrecarga, como la implementamos
  con int e interactuar con string, y por que tiene sentido tener las dos versiones.
- Como Zona recorre sus elementos con for clasico y por que los elementos usados
  desaparecen de la lista.
- El flujo general de EcoMision: el while activo, como funciona turno(),
  procesarOpcion() y verificarFinJuego().
- La condicion de victoria: como hayVictoria() recorre todas las zonas usando
  getCodigos() y consulta tieneResiduosSinLimpiar() y tieneFuentesSinRestaurar().

### Eddy Andrés Escobar
Eddy se encargo de la jerarquia de herencia y el estado del jugador: las clases
ElementoInteractivo, todas sus subclases y Explorador. Debe poder explicar y defender:

- Por que ElementoInteractivo es abstracta y que significa que interactuar() sea
  virtual puro.
- Para que sirven getTipo(), getEfecto() y fueUsado() como metodos virtuales puros
  y por que esa decision fortalece el polimorfismo.
- El comportamiento especifico de cada subclase: que hace cada una en interactuar(),
  que estado interno maneja (curado, limpiado, restaurada, etc.) y por que cada una
  verifica energia antes de actuar.
- Por que FuenteContaminada necesita dos interacciones para restaurarse y como
  limpiezasPendientes controla ese estado.
- El Explorador: sus atributos, por que el inventario es un vector de punteros y
  no de strings, y como cambiarZona() implementa la asociacion con Zona.
- El concepto de polimorfismo en la practica: cuando Zona llama
  elementos[i]->interactuar(&explorador), como el programa decide en tiempo de
  ejecucion cual subclase ejecutar.
