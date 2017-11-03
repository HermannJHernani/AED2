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
