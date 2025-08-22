#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void rle_encode(char *s){
    int conteo=0;
    int capacidadCadena= strlen(s);
    for(int i=0;i<capacidadCadena;i++){
        if(s[i]==s[i+1]){
            conteo++;
        }else{
            conteo++;
            printf("%c%d",s[i],conteo);
            conteo=0;
        }
    }
    printf("\n");
}

void rle_decode(char *s){
    int capacidadCadena= strlen(s);
    char cadenaTemp[capacidadCadena];
    char caracterTemporal;
    int tempoDigito;
    char auxiliar[2];

    cadenaTemp[0] = '\0'; //Para que elimine basura ahí
    
    for(int i=0;i<capacidadCadena;i++){
        if(isalpha(s[i])){
            caracterTemporal=s[i];
        }
        if(isdigit(s[i])){
            while(isdigit(s[i])){
                auxiliar[0]=s[i];
                auxiliar[1]='\0';
                strcat(cadenaTemp,auxiliar);
                i++;
            }
            tempoDigito = atoi(cadenaTemp);
            imprimirTexto(caracterTemporal,tempoDigito);
            cadenaTemp[0] = '\0'; //Para que elimine basura ahí
            i--;
        }
    }
    free(cadenaTemp);
    printf("\n");
}

void imprimirTexto(char caracterT,int intT){
    for(int i=0;i<intT;i++){
        printf("%c",caracterT);
    }
}

char* leer_cadena_dinamica() {
    
    int capacidad =10;
    char *cadena = malloc(capacidad * sizeof(char));
    int cTemp;
    char *temp;
    int espacioTemp=0;
    int conteoCaracteres=0;

    if(cadena ==NULL){
        printf("Error al ocupar memoria");
    }

    printf("\n: ");

    //Vamos leyendo caracter por caracter
    while((cTemp = getchar()) !='\n' && cTemp != EOF && cTemp != ' '){
        
        if(espacioTemp>1000000){
            printf("\n\nEl ESPACIO DE CADENA EXCEDE EL LIMITE");
            return NULL;
        }
        if(espacioTemp>=capacidad-1){
            capacidad = capacidad*10;
            

            temp  = realloc(cadena, capacidad * sizeof(char));
            if(temp ==NULL){
                printf("Error en el redimensionamiento");
                free(cadena);
                return NULL;
            }
            cadena= temp;
        }

        cadena[espacioTemp] = (char) cTemp;
        espacioTemp++;
    }
    cadena[espacioTemp] = '\0';

    return cadena;
}

int main(){
    char mode[7];
    
    printf("\n:");
    scanf("%s", mode);
    
    // Limpiar el \n que genera el ENTER
    while(getchar() != '\n');
    
    char *cadena = leer_cadena_dinamica();
    if (cadena == NULL) {
        return 1;
    }
    
    if(strcmp(mode,"ENCODE")==0){
        rle_encode(cadena);
    }else if(strcmp(mode,"DECODE")==0){
        rle_decode(cadena);
    }else{
        printf("Modo no válido. Use ENCODE o DECODE\n");
        free(cadena);
        return 1;
    }
    
    free(cadena);
    return 0;
}