#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cadastro{
    char nome[50], email[30];
    int tel;
}cadastro;
void adicionar(cadastro **array, int *total){
    cadastro novo;
    printf("nome, email e telefone\n");
    fgets(novo.nome, 50, stdin);
    fgets(novo.email, 30, stdin);
    scanf("%d", &novo.tel);
    getchar();
    cadastro *temporario;
    temporario = realloc(*array, (*total + 1) * sizeof(cadastro));
    if (temporario == NULL){
        printf("falha ao adicionar cadastro");
        return;
    }
    *array = temporario;
    (*array)[*total] = novo;
    (*total)++;
}

 
int main(){
    int total = 0;
    cadastro *array = NULL;
    int opc;
    do{
        printf("digite 1 para adicionar um novo contato e 2 para sair");
        scanf("%d", &opc);
        getchar();
        if(opc == 1){
        adicionar(&array, &total);
        }
    }while(opc != 2);
    return 0;
}