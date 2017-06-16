#include "gpio-out.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
	char comando[213] = {};
	strcat(comando, "100100100110110100100100100110110100100110110110110110110110110110100110");
    char Open[40] = {};
	strcat(Open, "1001010110000100110000010100000000110000");
	char Close[40] = {};
	strcat(Close, "0110100101011000010011001000000000000101");
    if (argc != 2) // Comando mais numero de portao)
	{
        printf("Erro nos argumentos.\n Para Usar: autoaudi [open/close]\n");
	}
	else
	{
		int i = 0;
        if (strcmp(argv[1],"open")==0){
			for (i = 0; i < 40 ; i++){
				if (Open[i]=='0')
					strcat(comando, "100");
				else
					strcat(comando, "110");
			}
		}
		else if (strcmp(argv[1],"close")==0){
			for (i = 0; i < 40 ; i++){
				if (Close[i]=='0')
					strcat(comando, "100");
				else
					strcat(comando, "110");
			}
		}
		else{
			printf("Erro na função.\n Função deve ser \"open\" ou \"close\".\n");
        }
	}
	strcat(comando, "000111111111111000000");
	if (strlen(comando) == 213) 
		{       
	setgpio();
	SendCodeAudi(comando);
	}   	
	return 0 ;
}
