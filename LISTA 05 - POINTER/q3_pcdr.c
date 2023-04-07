#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    char ch;
    int start_len=100;
    int current_len=0;
    char *lista1 = (char*) malloc(start_len*sizeof(char)); 
    char *lista2 = (char*) malloc(start_len*sizeof(char));
    int count=1;
    int i;
    int j;
    char amigo[31];
// lista 1
    i=0;
    while((ch = getchar()) != '\n'){
        if(i==current_len){
            current_len=i+start_len;
            lista1 = (char*)realloc(lista1,current_len); 
        }
        lista1[i]=ch;
        i++;
    }
    lista1[i]='\0';
    current_len=0;
// lista2
    i=0;
    while((ch = getchar()) != '\n'){
        if(i==current_len){
            current_len=i+start_len;
            lista2 = (char*)realloc(lista2,current_len); 
        }
        lista2[i]=ch;
        i++;
    }
    lista2[i]='\0';
// count
    j=0;
    while (lista1[j]!='\0'){
        if(lista1[j]==' '){
            count++;
        }
        j++;
    }
// nome do amigo
    scanf("%s", amigo);
// matrix das listas por palavra
    char *matrix[count];
    char *palavra = strtok(lista1, " ");
    int k = 0;
    matrix[k]=(char *)malloc(31*sizeof(char));
    strcpy(matrix[k],palavra);
    while (palavra!=NULL){
        matrix[k]=(char *)malloc(31*sizeof(char));
        strcpy(matrix[k++],palavra);
        palavra = strtok(NULL, " ");
    }
// printar
    if (strcmp("nao",amigo)==0){
        for (int i=0;i<count;i++){
            printf("%s ", matrix[i]);
        }
        printf("%s",lista2);
    }else{
        for(int i=0;i<count;i++){
            if(strcmp(matrix[i],amigo)!=0){
                
                if (i==(count-1)){
                    printf("%s", matrix[i]);
                }else{
                    printf("%s ", matrix[i]);
                }
            }else if(strcmp(matrix[i],amigo)==0){
                if (i==(count-1)){
                    printf("%s %s",lista2, matrix[i]);
                }else{
                    printf("%s %s ",lista2, matrix[i]);
                }
            }
        }
    }
    printf("\n");
    for (int m=0;m<count;m++){
        free(matrix[m]);
    }
    free(lista1);
    free(lista2);
    return 0;
}