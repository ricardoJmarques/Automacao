#include <string.h>
#include <stdlib.h>

int setcanal (char canal, char *comando){
    switch (canal){
        case 'A':
            strcat(comando, "10001000100010001000100010001000");
        break;
        case 'B':
            strcat(comando, "10001110100010001000100010001000");
        break;
        case 'C':
            strcat(comando, "10001000100011101000100010001000");
        break;
        case 'D':
            strcat(comando, "10001110100011101000100010001000");
        break;
        case 'E':
            strcat(comando, "10001000100010001000111010001000");
        break;
        case 'F':
            strcat(comando, "10001110100010001000111010001000");
        break;
        case 'G':
            strcat(comando, "10001000100011101000111010001000");
        break;
        case 'H':
            strcat(comando, "10001110100011101000111010001000");
        break;
        case 'I':
            strcat(comando, "10001000100010001000100010001110");
        break;
        case 'J':
            strcat(comando, "10001110100010001000100010001110");
        break;
        case 'K':
            strcat(comando, "10001000100011101000100010001110");
        break;
        case 'L':
            strcat(comando, "10001110100011101000100010001110");
        break;
        case 'M':
            strcat(comando, "10001000100010001000111010001110");
        break;
        case 'N':
            strcat(comando, "10001110100010001000111010001110");
        break;
        case 'O':
            strcat(comando, "10001000100011101000111010001110");
        break;
        case 'P':
            strcat(comando, "10001110100011101000111010001110");
        break;
    }
    return 0;
}

int setnumero (char numero, char *comando){
    switch (numero){
        case '1':
            strcat(comando, "1000100010001000");
        break;
        case '2':
            strcat(comando, "1000111010001000");
        break;
        case '3':
            strcat(comando, "1000100010001110");
        break;
        case '4':
            strcat(comando, "1000111010001110");
        break;
    }
    return 0;
}

int setgrupo (char grupo, char *comando){
    switch (grupo){
        case '1':
            strcat(comando, "1000100010001000");
        break;
        case '2':
            strcat(comando, "1000111010001000");
        break;
        case '3':
            strcat(comando, "1000100010001110");
        break;
        case '4':
            strcat(comando, "1000111010001110");
        break;
    }
    return 0;
}

int setfuncao (char *funcao, char *comando){
    if (strcmp(funcao,"on") == 0)
        strcat(comando, "10001000100011101000111010001110");
    else
        strcat(comando, "10001000100011101000111010001000");
    return 0;
}
