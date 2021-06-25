#include <iostream>
#include <locale.h>
#include <fstream>
#include "triangulo.h"

using namespace std;

int main() {

  setlocale(LC_ALL, "Portuguese");
  tLista* triangulos = new tLista;
  tTriangulo t;
  int quant, opcao;

  cout <<"1. gravar 2. ler\n";
  cin >> opcao;

  if(opcao==1){
    inicializaLista(triangulos); 
    cout << "digite quantos triangulos\n";
    cin >> quant;
    
    for(int i = 0; i < quant; i++){
      cout << "digite os lados dos triangulos\n";
      cin >> t.lado1 >> t.lado2 >> t.lado3;
      incluirNoFim(triangulos, t);
    }
  }
  if(opcao==2){
    cout << "leitura do banco de dados: \n"; 
  }

  //imprimirLista(triangulos);

}