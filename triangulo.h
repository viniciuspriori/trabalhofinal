#ifndef TRIANG_H
#define TRIANG_H
#include <iostream>
// #include <fstream>
// #include <locale.h>
using namespace std;

struct tTriangulo{
  int lado1;
  int lado2;
  int lado3;
};

struct tNo{
  tTriangulo info;
   //aqui vai a struct
  tNo* proximo;
};

struct tLista{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};


void inicializaLista(tLista*);
void incluirNoFim(tLista*, tTriangulo);
void imprimirLista(tLista*);
void gravaTxt(tLista*);

#endif