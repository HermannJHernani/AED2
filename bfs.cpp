#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <cstdlib>

#define MAX 55
#define nullptr 0
using namespace std;

class Item {
public:
	int casa, peso;
	int d;
	
	void imprime() {
		cout<< casa;
	//	cout<<peso<<endl;
	}
};

class No {
public:
    Item item;
    No *prox;
};

class Lista  {
public:
    No *prim, *ult;
    int tam, distancia, f;
    int pred;
    char cor;
    Lista();
    void flVazia();
    bool vazia();
    void insere(Item);
    void imprime();
    void imprimeTopo();
};


Lista::Lista() {       //inicializa lista
    flVazia();
}

void Lista::flVazia() {
    prim = new No();
    ult = prim;
    ult->prox = nullptr;
    tam = 0;
}
bool Lista::vazia() {     
    return prim == ult;
}
void Lista::insere(Item it) {
    ult->prox = new No();
    ult = ult->prox;
    ult->prox = nullptr;
    ult->item = it;
    tam++;
}
void Lista::imprime() {
    for(No *nav = prim->prox; nav != nullptr; nav = nav->prox) {   
        nav->item.imprime();
        if (nav->prox!=nullptr) cout << " -> ";
    }
    cout << "\n";
}

class NoFila {
public:
    Item item;
    NoFila *ant;
    NoFila() {};
};
class Fila {
public:
    NoFila *frente, *tras;
    void ffVazia();
    Fila();
    bool vazia();
    void enfileira(Item);
    void imprime();
    Item desenfileira();
};

Fila::Fila() {
    ffVazia();
}
void Fila::ffVazia() {
    frente = new NoFila();
    tras = frente;
    tras->ant = nullptr;
}
bool Fila::vazia() {
    return frente == tras;
}
void Fila::enfileira(Item it) {
    tras->ant = new NoFila();
    tras = tras->ant;
    tras->item = it;
    tras->ant = nullptr;
}
Item Fila::desenfileira() {
	Item it;
    if (vazia()) {
        cout << "Fila vazia.\n";
    }
    else {
        NoFila *q = frente;
        frente = frente->ant;
        it = frente->item;
        delete q;
        return it;
    }
}
void Fila::imprime() {
    for(NoFila *nav = frente->ant; nav != nullptr; nav = nav->ant) {
        nav->item.imprime();
    }
    cout << "\n";
}

class Grafo{
public:
	Lista *adj;
	
	int n;
	int m;
	int dist[MAX];
	int visitados[MAX];
	
	int predecessores[MAX];

	Grafo();
	Grafo(int);
	void insereAresta(int, int, int);
	void imprimeListaAdj();
	
	void bfs(int);
	
	void dfs(Lista&);
	void dfsVisita(int, Lista&);

};

Grafo::Grafo(){
}


Grafo::Grafo(int n){
//inicializa lista
	this->n=n;
	adj = new Lista[n+1];
	for(int i=0; i<=n; i++){
		adj[i].flVazia();
	}
	

}
void Grafo::insereAresta(int u, int v, int pesos){
	//add na lista
	Item x;
	x.casa=v;
	x.peso = pesos;
	adj[u].insere(x);
	x.casa = u;
	x.peso = pesos;
	adj[v].insere(x);

	

	m++;
}



void Grafo::imprimeListaAdj(){
	for (int i = 1; i<=n; i++){
		cout<<"v[" << i <<"] = ";
		adj[i].imprime();
	}



}
void Grafo::bfs(int origem){
	for (int i=1;i<=n;i++){
		adj[i].distancia=0;        //inicializa distancia de todos como 0 e cor como branca
		adj[i].cor='b';
	}
	
	Fila Q;
	Item x;
	
	adj[origem].cor='c';          //visita o vertice origem -> cor cinza
	x.casa=origem;
	Q.enfileira(x);                //enfileira a origem
	
	int u;
	while(!Q.vazia()){
		u=Q.desenfileira().casa;         //desenfileira o primeiro elemento
		for(No *nav = adj[u].prim->prox; nav != nullptr; nav = nav->prox){    // percorre os vertices adjacentes, se a cor do vertice for branca(nao visitado), 
			if (adj[nav->item.casa].cor=='b'){                                // ela se torna cinza e a distancia desse vertice aumenta +1
				adj[nav->item.casa].cor='c';                                   // enfileira-se os vertices adjacentes
				adj[nav->item.casa].distancia=adj[u].distancia+1;
				Q.enfileira(nav->item);
			}
		adj[u].cor='p';    // quando todos os vertices adjacentes tiverem sido visitados, a cor se torna preta
		}
	}
	cout<<"Imprimindo o bfs"<<endl;
	for(int i=1; i<=n; i++){
		cout<< "a distanca de " << origem << " para " << i << ": " << adj[i].distancia<<endl;
	}
}

class Arquivo{
	public:
		string linha;
		
		void lerArquivo(Grafo&);
		
};

void Arquivo::lerArquivo(Grafo &g){
	string linha;
	
	ifstream grafo("Grafo1.txt");
	int a = 0;
	int b = 0;
	
	
	if(grafo.is_open()&&grafo.good()){
		int cont = 0;
		while(!grafo.eof()){
			getline(grafo, linha);
			if(cont==0){
				a = (atoi(linha.c_str()));	
			}else{
				linha = linha + " ";
				int indice = linha.find_first_of(" ");
				string vert = linha.substr(0, indice);
			
				linha = linha.substr((indice+1));
				indice = linha.find_first_of(" ");
				string vert2 = linha.substr(0, indice);
			
				linha = linha.substr(indice+1);
				indice = linha.find_first_of(" ");
				
				string peso = linha.substr(0, indice);
				
				g.insereAresta(atoi(vert.c_str()), atoi(vert2.c_str()), atoi(peso.c_str()));
				
			}
			cont ++;
		
			Grafo(a);
			
		}
	}
}

int main(int argc, const char *argv[]){
	
	string line;
	
	Lista l;
	char c;
	ifstream grafo("Grafo1.txt");
	if(grafo.is_open()&&grafo.good()){
		c = grafo.get();
	}
	int n = int(c) - 48;
	
	Grafo g(n);
	
	
	Arquivo arq;
	arq.lerArquivo(g);

	
	g.bfs(5);

	return 0;	
}
