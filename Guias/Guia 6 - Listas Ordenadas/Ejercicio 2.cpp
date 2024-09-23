#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

/*Se dispone del archivo binario G06E02.bin que contiene una lista no ordenada de órdenes de
compras. Las mismas tienen los siguientes campos: id es un entero con un número que no se
repite en ninguna otra orden. Cliente es un string que se guarda en el archivo binario con un
largo de 8 caracteres. Producto también es string y se guarda con largo 10. Cantidad es un
entero con la cantidad pedida de ese producto por el cliente.

a. Se debe leer el archivo y cargar dos listas, la primera ordenada por cliente y a igualdad de
cliente por producto (siempre ascendente). La otra por id (también ascendente). Luego de
cargar las listas se mostrarán ambas por pantalla.

b. La lista ordenada por id está pensada para consultas, por eso luego de cargar las listas el
programa pedirá un id, lo buscará y mostrará todos los datos de la orden de compra
correspondiente o bien informará que no hay ninguna con ese número. El ciclo se corta
cuando se ingresa un id negativo, ya que todos los id correctos son positivos.

c. Luego se pasa al despacho, para eso se pide al operador un nombre de cliente y un
producto, de haber, se eliminan todos los registros correspondientes de AMBAS listas. A
medida que se borran los registros se van mostrando por pantalla los eliminados, y una vez
que se eliminaron todos los que corresponde, se muestran como quedaron ambas listas.
Esto se hace en un ciclo hasta que se ingresa EOF.

Nota: se provee el archivo G06E02.bin y la salida al mostrar las listas por primera vez.

*/