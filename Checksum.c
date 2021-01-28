#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80
#define M 20
int main(){
    char carattere[N];
    int bin[N], checksum[M], decimale;
    int i, j, temp, cont, par, cont2, flag;

	decimale = 0;

	for(i = 0; i < M; i++){
		checksum[i] = 0;
	}
	
	
    printf("Inserisci la stringa\n");
    gets(carattere);

    printf("La stringa alla fine di questa frase vale: FRASE  >>> ");
    puts(carattere);
    for(i = 0; i < strlen(carattere); i++){
    	if(i == 0){
    		flag = 0;
		}
		else{
			flag = 1;
		}
    	cont2 = 0;
        temp = (int)carattere[i];
        for(j = 0; temp >= 1; j++){
            bin[j] = temp % 2;
            temp = temp / 2;
            cont2++;
            
    	}
        
        temp = j;
        
        for(j = cont2 - 1; j >= 0; j--){
        	checksum[j] = checksum[j] ^ bin[j];
		}

        
        printf("\n%c %d ", carattere[i], (int)carattere[i]);
        cont = 0;
        for(j = cont2 - 1; j >= 0; j--){
            if(bin[j] == 1){
            	printf("1");
                cont++;
            }
            else{
            	if(bin[j] == 0){
            		printf("0");
				}
			}
        }
        par = cont % 2;

        if(par == 0){
            printf(" La parita e' pari ");
        }
        else{
            printf(" La parita e' dispari ");
        }
        if(flag != 0){
			printf("Il risultato dello XOR tra la lettera %c e la lettera %c e' ", carattere[i - 1], carattere[i]);
			for(j = cont2 - 1; j >= 0; j--){
        		printf("%d", checksum[j]);
			}
		}
		else{
			printf("NESSUN CALCOLO ESEGUITO QUI (CALCOLO TRA LA PRIMA LETTERA E 0)");
		}
            
    }
    printf("\n");
    
    for(i = temp; i >= 0; i--){
    	decimale = 2 * decimale + checksum[i];
	}
    
	printf("Il checksum della parola e' %d\n", decimale);
    system("pause");
}
