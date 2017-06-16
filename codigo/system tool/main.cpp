#include "gpio-out.hpp"
#include "remotecode.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
    char comando[100] = {};
    char canal;
    char numero;
    char grupo;
    if (argc != 5) // Comando + 4 argumentos (Canal - Numero - Grupo - Função)
	{
        printf("Erro no numero de argumentos.\n Para Usar: automacao [A-P] [1-4] [1-4] [on/off]\n");
	}
	else
	{
        canal = argv[1][0];
        numero = argv[2][0];
        grupo = argv[3][0];
        if (canal < 65 || canal > 80){
            printf("Erro no argumento Canal.\n Canal deve estar entre A e P.\n");
            }
        else{
            setcanal(canal, comando);
            }
        if (numero < 49 || numero > 52){
            printf("Erro no argumento Numero.\n Numero deve estar entre 1 e 4.\n"); 
            }
        else{
            setnumero(numero, comando);
            }
        if (grupo < 49 || grupo > 52){
            printf("Erro no argumento Grupo.\n Grupo deve estar entre 1 e 4.\n");
            }
        else{
            setgrupo(grupo, comando);
            }
       	if (strcmp(argv[4],"on") == 0 || strcmp(argv[4],"off") == 0){
	        setfuncao(argv[4], comando);
         }
	    else{
            printf("Erro no argumento funcao.\n Funcao deve ser \"on\" ou \"off\".\n");
            }
    }
    strcat(comando, "1000"); //Adicionar ultimo bit a zero
    if (strlen(comando) == 100) 
	{       
	setgpio();
	SendCode(comando);
	}    
	return 0 ;
}
