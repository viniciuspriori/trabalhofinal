#include <iostream>
#include <fstream>
#include <locale.h>
#include "triangulo.h"

using namespace std;

tNo* criaNo(tTriangulo t){
  tNo* no = new tNo;
  no -> info = t;
   //struct
  no -> proximo = NULL;
  return no;
}

void inicializaLista(tLista* pLista){
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
    pLista -> marcador = NULL;
    pLista -> tamanho = 0;
    cout << "Lista inicializada. \n\n";
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

    //cout << "\nObjeto incluido na lista." << endl; 
}

void imprimirLista(tLista* pLista){
  cout << "\nImprimindo lista: \n" << endl;
  pLista -> marcador = pLista -> primeiro;

  while(!finalLista(pLista)){
    tTriangulo t = pLista -> marcador -> info; //

    cout << "Lado 1: " << t.lado1 << "\n" << "Lado 2: "<< t.lado2 << "\n" << "Lado 3: " << t.lado3 << endl;
    cout << "----------------" << endl;

    pLista -> marcador = pLista -> marcador -> proximo; 
  }
}

void gravaTxt(tLista* pLista){

  ofstream grava; 
  grava.open("tri.txt", ios::out);

  pLista -> marcador = pLista -> primeiro;

  while(!finalLista(pLista)){
    tTriangulo t = pLista -> marcador -> info;
 
    grava << pLista -> marcador -> info.lado1 << " ";
    grava << pLista -> marcador -> info.lado2 << " ";
    grava << pLista -> marcador -> info.lado3 << endl;

    pLista -> marcador = pLista -> marcador -> proximo;
  }

  grava.close();
}

void leTxt(tLista* pLista){
  ifstream le; 
  le.open("tri.txt", ios::in);
  
  pLista -> marcador = pLista -> primeiro;
  tTriangulo t;
  while(le >> t.lado1 >> t.lado2 >> t.lado3){
    incluirNoFim(pLista, t);
  }
  le.close();
}