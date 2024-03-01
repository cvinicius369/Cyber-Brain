#ifndef nucleo_b
#define nucleo_b
#include <iostream>     // biblioteca excenssial para o bom funcionamento do software                           
#include <string>       // bibliotexa que permite o uso de strings
#include <ctime>        // biblioteca que permite a manipulacao do tempo
using namespace std;    // espaco que permite o uso de funcoes sem mencionar o termo "std::nome_da_funcao"

struct dados{
    string nome = "EVA";
};

void Ativa(){
    dados d;
    nucleo_a::Styles s;
    inicio: 
    cout << "Bem vindo(a)!\nMe chamo " << d.nome << " Prazer em te conhecer, o que deseja fazer agora?" << endl;
    cout << "[1] - Acessar Sistema Neural\n"    << "[2] - Acessar Sistema Quantico\n"
         << "[3] - Acessar sistema Molecular\n" << "[4] - Conversar\n" << "[5] - Sair\n->";
    int action; cin >> action;
    s.LineStyle();

    if (action == 1){ nucleo_a::menu(); }
    else if (action == 5){ cout << "Até breve! Espero ter ajudado! ^^" << endl; }
    else { cout << "Desculpe! Eu não entendi.." << endl; goto inicio; }
    s.LineStyle();
}
#endif