/******************************************************************************
AED2
Amanda Leticia Mineiro Chaves 
Backtracking em c. Dado um tabuleiro com n x n posições, o cavalo movimenta-se segundo as regras do xadrez. 
Enconte um passeio de um cavalo no tabuleiro de xadrez que visite todas as posições do t
*******************************************************************************/

#include <stdio.h>

//board of n x n
int input(){
    
    int n;
    printf("Qual o tamanho do tabuleiro: ");
    scanf("%d", &n);

    return n;
}

//check if it is inside the chessboard and if the cell is not already occupied
int is_valid(int N, int i, int j, int sol[N+1][N+1]) { 
    
    if (i>=1 && i<=N && j>=1 && j<=N && sol[i][j]==-1)
        return 1;
    return 0;
}

int knight_tour(int N, int sol[N+1][N+1], int i, int j, int step_count, int x_move[], int y_move[]) {

    if (step_count == N*N)  //check if the solution is found.
        return 1;

    int k;
    for(k=0; k<8; k++) {  //move to the next possible knight's
        int next_i = i+x_move[k];
        int next_j = j+y_move[k];

        if(is_valid(N, i+x_move[k], j+y_move[k], sol)) {  //check if the cell is valid
            sol[next_i][next_j] = step_count;
            if (knight_tour(N, sol, next_i, next_j, step_count+1, x_move, y_move))
            return 1;
            sol[i+x_move[k]][j+y_move[k]] = -1; // backtracking
        }
    }
    
    //if none the possible move returns false
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

    //possible moves from a cell
    int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[1][1] = 0; // placing knight at cell(1, 1)

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
 
