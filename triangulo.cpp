#include <iostream>
#include "triangulo.h"

using namespace std;

tNo* criaNo(tTriangulo t){
  tNo* no = new tNo;
  no -> info = t;

  cout << "criando nó t.lado2 (2): " << no -> info.lado2 << endl; 
   //struct
  no -> proximo = NULL;
  return no;
}

void inicializaLista(tLista* pLista){
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
    pLista -> marcador = NULL;
    pLista -> tamanho = 0;
    cout << "Lista inicializada. \n";
}

int obterTamanho(tLista* pLista){
    return (pLista -> tamanho);
}

bool listaVazia(tLista* pLista){
  return (pLista -> tamanho==0);
}

bool finalLista(tLista* pLista){
  return (pLista -> marcador == NULL);
}

void incluirNoFim(tLista* pLista, tTriangulo t){
  tNo* no;
  no = criaNo(t);//

  if(listaVazia(pLista)){
    pLista -> primeiro = no; 
  } else {
      pLista -> ultimo -> proximo = no;
  } 
    pLista -> ultimo = no;
    pLista -> marcador = no;
    pLista -> tamanho ++;

    cout << "\nObjeto incluido na lista." << endl; 
}

void imprimirLista(tLista* pLista){
  cout << "\nImprimindo lista: " << endl;
  pLista -> marcador = pLista -> primeiro;

  while(!finalLista(pLista)){
    tTriangulo t = pLista -> marcador -> info; //

    cout << t.lado1 << " " << t.lado2 << " " << t.lado3 << " " << endl;

    pLista -> marcador = pLista -> marcador -> proximo; 
  }
}
