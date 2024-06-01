
Traductor

Proyecto final de programación III

¿Qué es usuario? Es la persona que utiliza un producto o servicio de red, bemeficiándose de algún modo de dicha 
utilización, simplemente utiliza el servicio.

¿Qué es registro? Es un documento u otra entidad física o electrónica de una organización que sirve como evidencia 
de una actividad o transacción realizada por la organización y que requiere retención durante un período de tiempo.

¿Cómo se hace el inicio de sesión de usuario en el programa? Se crea un vector en el cual se guardan lo usuarios 
previamente y otro vector donde se guardan las contraseñas y con condicionales if el usuario coincida con la contraseña
asignada en el espacio del vector, si la condición se cumple, ingresará al programa con exito, de lo contrario, el 
programa indicará que el usuario y/o contraseña son incorrectos, se hará con un límite de 3 intentos invalidos hasta 
que el programa bloquee el acceso y se cierre.

¿Qué es búsqueda? Es la consulta basada en un término de búsqueda específico que un usuario ingresa en un motor de 
búsqueda web para satisfacer sus necesidades de información.

¿Cómo se hace la búsqueda en el programa? En el programa se ha creado un objeto de la clase Ifstream llamado lec, 
posteriormente se utiliza la función miembro open para abrir el arcivo especificado en la cadena de texto que se 
encuentra dentro del paréntesis de la función. Con el ofstream lec lee todo el archivo y conforme a nuestro código 
busca la palabra clave, que en nuestro caso el cualquier palabra en español que estpe agregado en nustro archivjo txt, 
devolviendo la palabra en español conjunto a la palabra traducida en el idioma previamente seleccionado y mostrandolo 
en pantalla.

¿Cómo se reproduce el audio? Por medio de la libreria windows.h hará el enlace con el programa espeack para que haga 
la función de leer y reproducir las palarbas en el programa, tanto la solicitada como la traducción.

¿Qué es encriptar? Es la codificación de la información. Este proceso convierte la representación original de la información, 
conocida como texto plano, en una forma alternativa conocida como texto cifrado.

¿Cómo se hace la encriptación de las palabras? Cuando muestra en pantalla la palabra en español y su respectiva traducción, 
cada letra la encripta en una serie de letras y numeros previamente establecidos en un archivo de txt, es decir, hay un 
archivo txt en el cual contiene la letra y numero que representa cada letra de las palabras que se muestren en pantalla de 
las traducciones.

¿Cómo se hace para guardar más palabras? En el programa se ha creado un objeto de la clase Ofstream llamado esc, posteriormente
se utiliza la función miembro open para abrir el arcivo especificado en la cadena de texto que se encuentra dentro del paréntesis
de la función. Se elige la opción de registrar una palabra más en el archivo txt del respectivo idioma a elegir de traducción, 
se le pide al usuario que ingrese la palabra en español y que también lo ingrese traducido al idioma seleccionado y que a la hora
de darle aceptar lo guardará en el txt.

Interfaz del programa: La interfaz del menú está programa de tal manera que está con base de condicionales múltiples, es decir, 
según lo que ingrese el usuario al programa, el programa ejecutará lo solicitado, sin en dado caso el usuario ingresa una opción 
invalida, el programa le volverá a solicitar que ingrese alguna opción correcta en el parámetro indicado.

Eliminación de palabras: En el programa se ha creado un objeto de la clase Ifstream llamado lec, posteriormente se utiliza la 
función miembro open para abrir el arcivo especificado en la cadena de texto que se encuentra dentro del paréntesis de la función. 
Cuando el achivo este abierto nuestra variable lec recorrerá el archivo hasta encontrar la palabra seleccionada creando un archivo 
auxiliar en el que se copian todas las palabras del archivo principal para posteriormente eliminar la palabra en el mismo, si no se
encuentra la palabra, mostrará un mensaje de error de palabra no encontrada.
