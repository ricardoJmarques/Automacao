#include "gpio-out.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
    char comando[112] = {};
    char portao;
    if (argc != 2) // Comando mais numero de portao)
	{
        printf("Erro no numero de argumentos.\n Para Usar: portao \"numero\"\n");
	}
	else
	{
        portao = argv[1][0];
        if (portao < 49 || portao > 50){
            printf("Erro no numero de portão.\n Numero deve estar entre 1 e 2.\n"); 
            }
        else{
				if (portao == 49)
					strcat(comando, "1110100011101110100011101110111011101110100010001000100011101110100010001000111010001000110010001000100010001000");
				else
					strcat(comando, "1110100011101110100011101110111011101110100010001000100011101110100010001110100010001000111010001000100011101110");
            }
     }
    if (strlen(comando) == 112) 
	{       
	setgpio();
	SendCodePortao(comando);
		}    
	return 0 ;
}
