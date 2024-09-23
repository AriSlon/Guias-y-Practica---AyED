#include <iostream>
#include <fstream>

int main() {
    // Creamos un objeto de flujo de salida para escribir en un archivo
    std::ofstream archi("ejemplo.txt");

    if (archi.is_open()) {
        // Escribimos algo en el archivo
        archi << "Hola, mundo!";
        
        // Movemos el puntero de escritura 5 bytes desde el inicio del archivo
        archi.seekp(5, std::ios::beg);
        
        // Escribimos algo más en la nueva posición
        archi << "C++";
        
        // Movemos el puntero de escritura 3 bytes hacia atrás desde la posición actual
        archi.seekp(-3, std::ios::cur);
        
        // Escribimos algo más en la nueva posición
        archi << "XYZ";
        int caca {4};
        // Movemos el puntero de escritura 4 bytes hacia atrás desde el final del archivo
        archi.seekp(caca, std::ios::end);
        
        // Escribimos algo más en la nueva posición
        archi << "FI6666";
        
        // Cerramos el archivo
        archi.close();
    } else {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }

    return 0;
}
