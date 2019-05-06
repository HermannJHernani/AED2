/******************************************************************************
AED2
Amanda Leticia Mineiro Chaves 
Backtracking em c. Dado um tabuleiro com n x n posições, o cavalo movimenta-se segundo as regras do xadrez. 
Enconte um passeio de um cavalo no tabuleiro de xadrez que visite todas as posições do t
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[8] = {2, 1, -1, -2, -2, -1, 1, 2}, //combinação de movimentos possíveis do cavalo no xadrez
    b[8] = {1, 2, 2, 1, -1, -2, -2, -1};   

void imprime(int n,int tabuleiro[n][n]){ //imprime o tabuleiro na ordem em que cada casa foi visitada
    int i,j; 

    for(i=0;i<8;i++){ 

    for(j=0;j<8;j++){ 

        printf("%3d",tabuleiro[i][j]);} 
        printf("\n"); 

    }
}

int movimentoCavalo(int i, int x, int y, int n, int tabuleiro[n][n]){

    int u,v,  //x e y para proximas posições do cavalo
    k,  //controla a variação das 8 combinações diferentes do cavalo
    q,  //guarda retorno da função
    casas = (n * n) + 1;

    if(i==casas){ //Quando o cavalo tiver passado todas as casas 
        imprime(n,tabuleiro); 
        return 1;
    }  
    
    //executa movimentos
    for(k=0;k<8;k++){

        u = x + a[k];  
        v = y + b[k];
        //testa limites do tabuleiro
        if( (u>=0 && u<=7) && (v>=0 && v<=7)){

            if(tabuleiro[u][v]==0){ //posicao livre

                tabuleiro[u][v]=i; //registre o movimento
                q = movimentoCavalo(i+1,u,v,n,tabuleiro);

                if(q==0) tabuleiro[u][v]=0; //se não alcançou todos, desfaça 

                else return 1; // se alcançou todos, retorne 1
            }
        }
    }
    return 0;
}

int main(){
    int cont, n;

    printf("Qual o tamanho do tabuleiro: ");
    scanf("%d", &n);

    int tabuleiro[n][n];  //tabuleiro de 8 x 8

    memset(tabuleiro,0,sizeof(tabuleiro));
    cont =1;
    //inicializando o cavalo no tabuleiro
    tabuleiro[0][0]=1;
    movimentoCavalo(2,0,0,n,tabuleiro);
}

main();
 
