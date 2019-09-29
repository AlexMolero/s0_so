#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include "menu.h"
#include "core.h"


int main() {

    menu();
    char option[1];

    getOption(option);

    while(atoi(option)!=3){
        selectOption(option);
        menu();
        getOption(option);
    }
    return 0;
}