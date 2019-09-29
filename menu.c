#include <io.h>
#include <stdio.h>

void menu (){

    write(STDOUT_FILENO,"(1) Mostrar recetas\n", sizeof(char) * strlen("(1) Mostrar recetas\n"));
    write(STDOUT_FILENO,"(2) Exportar lista de la compra\n", sizeof(char) * strlen("(2) Exportar lista de la compra\n"));
    write(STDOUT_FILENO,"(3) Salir\n", sizeof(char) * strlen("(3) Salir\n"));




}
