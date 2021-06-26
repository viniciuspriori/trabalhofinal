#include <iostream>
#include <fstream>
#include <locale.h>
#include "triangulo.h"

using namespace std;

int main() {
  
  tLista* triangulos = new tLista;
  tTriangulo t;
  int quant, opcao;

  cout <<"No 1. Gravar \nNo 2. Ler\n";
  cin >> opcao;

  if(opcao==1){
    inicializaLista(triangulos); 
    cout << "Digite quantos triangulos\n";
    cin >> quant;
    
    for(int i = 0; i < quant; i++){
      cout << "\nDigite os lados dos triangulos\n";
      cin >> t.lado1 >> t.lado2 >> t.lado3;
      incluirNoFim(triangulos, t);
    }

    gravaTxt(triangulos);
  }
  
  if(opcao==2){
    inicializaLista(triangulos);
    cout << "Começando leitura do banco de dados. \n";
    leTxt(triangulos);
    imprimirLista(triangulos);
  }


  return 0;
}