#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void desarranjo(int posicao, char *entrada, int *visitados, char *resposta, int n){

    if(posicao == n){
        for(int i=0;i<n;i++){
            printf("%c ",resposta[i]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        if((i != posicao) && (visitados[i]==0)){
            visitados[i] = 1;
            resposta[posicao] = entrada[i];
            desarranjo(posicao+1, entrada, visitados, resposta, n);
            visitados[i] = 0;
        }
    }
}


int main(){
    char entrada[] = {'1','2','3','4'};
    int n;
    n = sizeof(entrada)/sizeof(char);
    int *visitados;
    char *resposta;
    visitados = malloc(n * sizeof(int));
    resposta = malloc(n * sizeof(char));

    memset(visitados,0,sizeof(visitados));

    desarranjo(0, entrada, visitados, resposta, n);

    free(visitados);
    free(resposta);
    return 0;
}
