#include <iostream>
#include <vector>
#include <list>


using namespace std;

template<typename T>
class Entrada{
private:
    vector<T> entrada;
    int casos;
    char jogadas;
    char jogada[];
    int casos;
public:
    Entrada (){}
    vector<T> getEntrada();
	  int recebeEntrada();
    int trataEntrada(T);
    void imprimeEntrada(T);
};

template<typename T>
vector<T> Entrada<T>::getEntrada(){
    return entrada;
}

template<typename T>
int vector<T> Entrada<T>::recebeEntrada(){
    int i;
    cin >> casos;
    for (i = 0; i < casos; i++){
      cin >> jogada;
      jogadas[i] = jogada;
    }
    return casos;
}

template<typename T>
int vector<T> Entrada<T>::trataEntrada(casos){
    return 1
}


int main(int argc, char const *argv[]) {
  Entrada recebeEntrada;
  Entrada trataEntrada;

  return

}
