#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include "triangulo.h"

using namespace std;

bool isInt(string str){
    for(int i = 0; i < str.length(); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

int lerQuantidadeTriangulos(){

    string quantidadeTriangulos;
    cout << "Digite a quantidade de triangulos: ";
    cin >> quantidadeTriangulos;

    if (isInt(quantidadeTriangulos)){
        return stoi(quantidadeTriangulos);
    }
    else{
        return lerQuantidadeTriangulos();
    }
}

string lerOpcao() {
    string opcao;
    cout << "Digite uma das seguintes opcoes:\n1 - Gravar\n2 - Ler\n3 - Sair\n";
    cin >> opcao;

    return opcao;
}

int main(){   

    tLista* triangulos = new tLista;
    tTriangulo t; 
    string opcao;

    do{
        opcao = lerOpcao();

        if(opcao == "1"){
            inicializaLista(triangulos);
            int quantidadeTriangulos = lerQuantidadeTriangulos();

            for (int i = 0; i < quantidadeTriangulos; i++){
              cout << "\nDigite os lados dos triangulos\n";
              cin >> t.lado1 >> t.lado2 >> t.lado3;
              incluirNoFim(triangulos, t);
            }
              gravaTxt(triangulos);
              continue;
        }
        else{
            if (opcao == "2"){
              inicializaLista(triangulos);
              cout << "Começando leitura do banco de dados. \n";
              leTxt(triangulos);
              imprimirLista(triangulos);
              continue;            
              }
        }

    }while (opcao != "3");

  return 0;
}