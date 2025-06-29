# SIEdit (traducido al español)

SIEdit es un visualizador y editor para el formato de empaquetación de assets que usa LEGO Island (La isla LEGO). Puede ver, extraer y reemplazar datos en todos los archivos SI del juego, permitiendo que texturas, sonidos, animaciones, información del entorno, vídeos, e incluso algo de la lógica/metadatos del juego puedan ser modificados. Actualmente sigue en desarrollo, pero debería funcionar con todos los archivos.

![SIEdit Screenshot](https://raw.githubusercontent.com/itsmattkc/SIEdit/master/packaging/screenshot.png)

## libweaver

Todo el código relacionado con SI está incluido en una librería separada escrita en C++ llamada **libweaver**, permitiendo que otros proyectos también puedan reusar los descubrimientos presentes aquí y trabajar con archivos SI. Actualmente no hay una documentación o API estable, sin embargo, debería ser bastante sencilla, y planeo agregar esas cosas en el futuro.

## Compilar

SIEdit y libweaver usan el sistema de compilación estándar CMake.

**SIEdit** requiere de Qt 6+ y FFmpeg para la IU y reproducción de medios respectivamente.

**libweaver** solo usa librerías estándares de C++98, y no debería necesitar nada especial.

## Futuro

Aquí hay una lista no-exhaustiva de cosas que me gustaría añadir en el futuro:

- Auto-conversión/conformación para reemplazar archivos más fácilmente. Actualmente cuando reemplazas archivos, necesitas manualmente convertirlos en el formato correcto antes de hacerlo (por ejemplo, un bitmap de 256 colores con una paleta de colores específica, Smacker 2, FLIC, WAV, etcétera). Estaría bueno que SIEdit hiciera esto automáticamente.
- Una API estable para libweaver. La librería es bastante usable así como está, pero no es la cosa más limpia del mundo ahora mismo, y me gustaría que otras personas pudieran usarla con el menor dolor de cabeza posible. Esta es mi primera vez haciendo una librería para uso en otros proyectos así que tal vez haga algunos errores.
- Poder crear archivos SI desde cero. Actualmente cualquier cambio debe usar un archivo SI ya existente como base. Sería interesante poder cargar archivos SI completamente personalizados en el juego. Esto tal vez requiera más ingeniería inversa, aunque creo que ya tenemos la mayoría del trabajo ya hecho.
  - Como una adición a esto, también estaría bueno el poder crear objetos nuevos en los SI (o sea, lo contrario a reemplazar lo que ya existe).
- Más lanzamientos para más plataformas. Actualmente solo distribuimos una build para Windows, lo cual es irónico ya que ni siquiera soy un usuario de Windows. Tal vez agreguemos una build para macOS y una AppImage para Linux, y tal vez intentaría configurar un paquete en la AUR ya que uso Arch (por cierto)
