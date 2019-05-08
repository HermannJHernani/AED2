/******************************************************************************
AED2
Amanda Leticia Mineiro Chaves 
Backtracking em c. Dado um tabuleiro com n x n posições, o cavalo movimenta-se segundo as regras do xadrez. 
Enconte um passeio de um cavalo no tabuleiro de xadrez que visite todas as posições do t
*******************************************************************************/

#include <stdio.h>

/*tabuleiro n x n*/
int input(){
    
    int n;
    printf("Qual o tamanho do tabuleiro: ");
    scanf("%d", &n);

    return n;
}

/*verifica se está dentro do tabuleiro de xadrez e se a posição ainda não está ocupada*/
int is_valid(int N, int i, int j, int sol[N+1][N+1]) { 
    
    if (i>=1 && i<=N && j>=1 && j<=N && sol[i][j]==-1)
        return 1;
    return 0;
}

/*leva a matriz de solução, a posição onde atualmente o cavalo está, a contagem de passos dessa célula 
e as duas matrizes para o movimento (x_move, y_move)*/
int knight_tour(int N, int sol[N+1][N+1], int i, int j, int step_count, int x_move[], int y_move[]) {
    
    /*verifica se a solução foi encontrada*/
    if (step_count == N*N)  
        return 1;

    int k;
    
    /*movimenta para a proxima posição possível*/
    for(k=0; k<8; k++) {  
        int next_i = i+x_move[k];
        int next_j = j+y_move[k];
        
        /*verifica se a posição é válida*/
        if(is_valid(N, i+x_move[k], j+y_move[k], sol)) {  
            sol[next_i][next_j] = step_count;
            if (knight_tour(N, sol, next_i, next_j, step_count+1, x_move, y_move))
                return 1;
            sol[i+x_move[k]][j+y_move[k]] = -1;
        }
    }
    
    /*se o movimento não é possível, retorna falso*/
    return 0;
}

int start_knight_tour(int N) {
    int sol[N+1][N+1];

    int i, j;
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            sol[i][j] = -1;
        }
    }

    /*movimentos possíveis do cavalo*/
    int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    //iniciando o cavalo na posição(1, 1) para 0*/
    sol[1][1] = 0; 
    
    if (knight_tour(N, sol, 1, 1, 1, x_move, y_move)) {
        for(i=1; i<=N; i++) {
            for(j=1; j<=N; j++) {
                printf("%d\t",sol[i][j]);
            }
            printf("\n");
        }
        return 1;
    }
    return 0;
}

int main() {
    
    int size = input();

    printf("%d\n",start_knight_tour(size));
    return 0;
}
 
