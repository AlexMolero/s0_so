//
// Created by Alex on 28/09/2019.
//
#include <fcntl.h>
#include "core.h"
#include "menu.h"
#define SHOW    1
#define EXPORT  2
#define FILENAME    "recetas.txt"

void getOption(char *cadena){

    int fd;
    int i = 0;
    char *buffer = NULL, opcion = ' ';

    write(STDOUT_FILENO,"Introduce la opcion: ", sizeof(char) * strlen("Introduce la opcion: "));

    while( opcion != '\n'){
        read(STDIN_FILENO,&opcion, sizeof(char));
        buffer = (char*) realloc (buffer,i+1);
        buffer[i] = opcion;
        if(opcion == '\n'){
            buffer[i] = '\0';
        }
        i++;
    }
    sprintf(cadena, " %s\n",buffer);
}
void showRecipe(){

     printf("ENTRA\n");
     int fd;
     char caracter = ' ';
     char buffer [1024];
     int length;
     fd = open("recetas.txt",O_RDONLY);
     if(fd < 0){
         write(STDERR_FILENO,"Error: No se ha podido abrir el fichero\n", sizeof(char)*strlen("Error: No se ha podido abrir el fichero\n"));
     }else {
         write(STDOUT_FILENO, "El fichero contiene: \n", sizeof(char) * strlen("El fichero contiene: \n"));
         while(read(fd,&caracter, sizeof(char) > 0)){
             write(STDOUT_FILENO,&caracter, sizeof(char));
         }
     }
    close(fd);

}
void selectOption(char *option){
    switch(atoi(option)){
        case SHOW:
            showRecipe();
            break;
        case EXPORT:
            printf("EXPORTAR\n");

            break;
        default:
            write(STDOUT_FILENO,"Opcion erronea, elige una opcion correcta\n", sizeof(char) * strlen("Opcion erronea, elige una opcion correcta\n"));

    }

}
