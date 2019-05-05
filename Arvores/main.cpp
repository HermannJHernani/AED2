#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef int Cor;
typedef int Vert;

#define BRANCO 0
#define CINZA 1
#define PRETO 2


//CLASSE LISTA !
template<typename T>

class List{
private:
    vector<T> lista;
public:
    List (){}
    vector<T> getList();
	  void insere(T);
    int busca(T);
    void remove(T);
    void imprime();
    void destroy();
};

//METODOS LISTA
template<typename T>
vector<T> List<T>::getList(){
    return lista;
}

template<typename T>
void List<T>::destroy(){
    vector<T>().swap(lista);
}

template<typename T>
void List<T>::insere(T posicao){
    lista.push_back(posicao);
}

template<typename T>
int List<T>::busca(T posicao){
    bool verificaPosicaoEncontrada = false;
    int posicaoEncontrada;

    for(int i = 0 ; i < lista.size() || verificaPosicaoEncontrada == false ; i++){
        if(posicao == lista[i]){
            posicaoEncontrada = i;
            verificaPosicaoEncontrada = true;
        }
    }

    if(verificaPosicaoEncontrada){
        return posicaoEncontrada;
    }
    else{
        return 0;
    }
}

template<typename T>
void List<T>::remove(T posicao){
    int buscaPosicao = busca(posicao);
    if(buscaPosicao == 0){
        cout << "Lista vazia ou posicao invalida" << endl;
    }
    else{
        lista.erase(lista.begin()+ buscaPosicao);
    }
}

template<typename T>
void List<T>::imprime(){
    for(int i = 0; i < lista.size();i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}
//FIM METODOS LISTA

//Classe MOVE
class Move{
private:
    pair<char,int> posicao;
    List< pair<char,int> > movimentos;
public:
    Move();
    Move(pair<char,int>par);
    void setPosicao(pair<char, int> par);
    void insereMovimentos(pair<char,int>,int,int);
    void listarMovimentos(pair<char,int>);
    void verificaMovimentos();
    void imprime();
};

//METODOS DA CLASSE MOVE
Move::Move(pair< char, int > par){
    this->posicao = par;
}

Move::Move(){
  this->posicao = make_pair(' ', 0);
}

void Move::setPosicao(pair< char, int > par){
    this->posicao = par;
}

void Move::insereMovimentos(pair<char,int> posicao, int frente, int lado){
    pair<char,int> chave;

    chave.first = posicao.first + frente;
    chave.second = posicao.second + lado;
    movimentos.insere(chave);

}

void Move::listarMovimentos(pair<char,int> posicao){

    insereMovimentos(posicao,2,-1);
    insereMovimentos(posicao,2,1);
    insereMovimentos(posicao,-2,-1);
    insereMovimentos(posicao,-2,1);
    insereMovimentos(posicao,1,-2);
    insereMovimentos(posicao,1,2);
    insereMovimentos(posicao,-1,-2);
    insereMovimentos(posicao,-1,2);

}

void Move::verificaMovimentos(){
    List<pair<char,int> > removerPosicao;

    for(int i = 0; i < movimentos.getList().size();i++){
        if(movimentos.getList()[i].first >= 'a' && movimentos.getList()[i].first <= 'h' && movimentos.getList()[i].second > 0 && movimentos.getList()[i].second < 9 ){    }
        else{
            removerPosicao.insere(movimentos.getList()[i]);
        }
    }

    for(int i = 0; i < removerPosicao.getList().size();i++){
        movimentos.remove(removerPosicao.getList()[i]);
    }
}

void Move::imprime(){
    verificaMovimentos();
    for(int i = 0;i < movimentos.getList().size();i++){
        cout << movimentos.getList()[i].first << movimentos.getList()[i].second << endl;
    }
}

//FIM METODOS MOVE


//Classe Grafo
class Grafo{
private:
    List<int> *adj;
    Move pos;
    int tam;
    int ordem;
    void destroy();
    int Cor;
    int pai;
public:
    Grafo(int);
    void inicializa(int);
    void insereAresta(Vert, Vert);
    void removeAresta(Vert, Vert);
    void setPosicao(Move);
    void printGrafo();
    void BFS(Grafo g, int v);
    void imprime();

};
//Metodos Grafo
Grafo::Grafo(int ordem){
    inicializa(ordem);
}

void Grafo::inicializa(int ordem){
    if(this->ordem != 0){
        destroy();
    }
    this->ordem = ordem;
    adj = new List<int>[ordem + 1];
}

void Grafo::insereAresta(Vert u, Vert v){
    int chave = v;
    adj[u].insere(chave);
    chave = u;
    adj[v].insere(chave);
    tam++;
}


void Grafo::imprime(){
    for(int i = 0; i < ordem; i++){
        cout << "Grafo [" << i << "] = ";
        adj[i].imprime();
    }
}

void Grafo::destroy(){
    for(int i = 0; i < ordem;i++){
        adj[i].destroy();
    }
    delete(adj);
    ordem = tam = 0;
}

void Grafo::BFS (Grafo g, Vert s){
    int i = 0;
    tam = g.size;

    while(i < g.tam){
        g[i].Cor = BRANCO;
        g[i].valor = -1;
		    g[i].pai = NULL;
		    i++;
    }
    s.Cor = CINZA;
    s.valor = 0;
    s.pai = NULL;

    vector<T> Q;
    Q.insere (Q,s);
    while(Q != NULL){
	    g = remove(Q);
	    while (i < g.adj.size){
	        if(g.adj[i].cor == BRANCO){
		        g.adj[i].cor = CINZA;
		        g.adj[i].valor = g[i].valor + 1;
		        g.adj[i].pai = g[i];
		        Q.insere (Q,g.adj[i]);
	        }
	        g.cor = preto;
	    }
    }

//faz uma bfs apartir de um vertice

}
//FUNCAO DE TESTE, APAGAR !
void testaGrafo(Grafo &g) {
	g.insertEdge(1, 2);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.insertEdge(4, 5);
	g.insertEdge(5, 1);
	g.insertEdge(5, 2);
	g.insertEdge(2, 4);
g.print();
}
//FIM FUNCAO DE TESTE

int main(int argc, const char *argv[]){
	int n, m;
	cout << "ordem: "; cin >> n;
	Grafo g(n);
	testaGrafo(g);

	return 0;
}
