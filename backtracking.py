import sys

class KnightsTour:
    def __init__(self, width, height):
        """
        Funcao de start, contendo altura e largura ou seja linhas e colunas da matriz,
        declaracao do nome da matriz e chamada da funcao de criacao do tabuleiro
        """
        self.w = width
        self.h = height

        self.board = []
        self.generate_board()

    def generate_board(self):
        """
        Cria uma linha aninhada para representar o tabuleiro
        """
        for i in range(self.h):
            self.board.append([0]*self.w)

    def print_board(self):
        """
        Funcao de print do tabuleiro
        """       
        print ("  ")
        print ("------")
        for elem in self.board:
            print (elem)
        print ("------")
        print ("  ")

    def generate_legal_moves(self, cur_pos):
        """
        Gerador de lista de movimentos aceitos que um cavalo pode fazer a seguir
        """
        possible_pos = []
        move_offsets = [(1, 2), (1, -2), (-1, 2), (-1, -2),
                        (2, 1), (2, -1), (-2, 1), (-2, -1)]

        for move in move_offsets:
            new_x = cur_pos[0] + move[0]
            new_y = cur_pos[1] + move[1]

            if (new_x >= self.h):
                continue
            elif (new_x < 0):
                continue
            elif (new_y >= self.w):
                continue
            elif (new_y < 0):
                continue
            else:
                possible_pos.append((new_x, new_y))

        return possible_pos

    def sort_lonely_neighbors(self, to_visit):
        """
        Eh mais eficiente visitar primeiro os vizinhos de canto,
        uma vez que estes estao nas bordas do tabuleiro de xadrez e nao pode
        ser alcancado facilmente se feito mais tarde na travessia
        """
        neighbor_list = self.generate_legal_moves(to_visit)
        empty_neighbours = []

        for neighbor in neighbor_list:
            np_value = self.board[neighbor[0]][neighbor[1]]
            if np_value == 0:
                empty_neighbours.append(neighbor)

        scores = []
        for empty in empty_neighbours:
            score = [empty, 0]
            moves = self.generate_legal_moves(empty)
            for m in moves:
                if self.board[m[0]][m[1]] == 0:
                    score[1] += 1
            scores.append(score)

        scores_sort = sorted(scores, key = lambda s: s[1])
        sorted_neighbours = [s[0] for s in scores_sort]
        return sorted_neighbours

    def tour(self, n, path, to_visit):
        """
        Recursao do tour dos cavalos. Inputs sao os seguintes:
        n = eh a atual arvore de busca em profundidade
        path = caminho atual
        to_visit = no a ser visitado
        """
        self.board[to_visit[0]][to_visit[1]] = n
        path.append(to_visit) #acrescente o vertice mais recente ao ponto atual 
        print ("Visiting: ", to_visit)

        if n == self.w * self.h: #se todo o tabuleiro foi percorrido
            self.print_board()
            print (path)
            print ("Done!")
            sys.exit(1)

        else:
            sorted_neighbours = self.sort_lonely_neighbors(to_visit)
            for neighbor in sorted_neighbours:
                self.tour(n+1, path, neighbor)

            #Se sair desse loop, todos os vizinhos deram errado, entao o resetamos
            self.board[to_visit[0]][to_visit[1]] = 0
            try:
                path.pop()
                print ("Going back to: ", path[-1])
            except IndexError:
                print ("No path found")
                sys.exit(1)

if __name__ == '__main__':
    #Input definindo o tamanho do tabuleiro e chamada das funcoes
    n = int(input("Tamanho do tabuleiro: "))
    kt = KnightsTour(n, n)
    kt.tour(1, [], (0,0))
    kt.print_board()