#ifndef nucleo_b
#define nucleo_b
#include <iostream>     // biblioteca excenssial para o bom funcionamento do software                           
#include <string>       // bibliotexa que permite o uso de strings
#include <ctime>        // biblioteca que permite a manipulacao do tempo
#include <vector>
#include <cstdlib>
using namespace std;    // espaco que permite o uso de funcoes sem mencionar o termo "std::nome_da_funcao"

struct dados{
    string nome = "EVA";
};

// Função para calcular a pontuação de polaridade de um texto.
double get_polarity_score(const string& text) {
    // Cria um vetor de palavras.
    vector<string> words;

    for (char c : text) { if (isalpha(c)) { words.push_back(string(1, c)); } } // Separa o texto em palavras.

    // Calcula a pontuação de polaridade de cada palavra.
    vector<double> scores;
    for (string word : words) {
        // Se a palavra é positiva, a pontuação é 1.
        if (word == "good" || word == "great" || word == "awesome") { scores.push_back(1.0); }
        // Se a palavra é negativa, a pontuação é -1.
        else if (word == "bad" || word == "terrible" || word == "awful") { scores.push_back(-1.0); }
        else { scores.push_back(0.0); } // Se a palavra não é positiva nem negativa, a pontuação é 0.
    }

    // Calcula a média das pontuações.
    double score = 0.0;
    for (double s : scores) { score += s; }
    score /= scores.size(); return score;   // Retorna a pontuação de polaridade.
}

// Função para classificar um texto em duas categorias: positivo ou negativo.
string classify_text(const string& text) {
    double score = get_polarity_score(text);  // Calcula a pontuação de polaridade do texto.

    if (score >= 0.0) { return "positive"; }// Se a pontuação de polaridade é maior ou igual a 0,0, o texto é positivo.
    else { return "negative"; }             // Se a pontuação de polaridade é menor que 0,0, o texto é negativo.
}

void ClassificaConversa(){
    cout << "Fique a vontade para digitar! ^^" << endl;
    cout << "Digite um texto: ";                     // Solicita ao usuário para digitar um texto.
    string text; cin >> text;
    string category = classify_text(text);           // Classifica o texto em duas categorias: positivo ou negativo.
    cout << "O texto é " << category << "." << endl; // Exibe a categoria do texto.
}

void Poema(){
    nucleo_a::Styles s;

    cout << "Certo, o que acha desse poema que acabei de criar? " << endl;
    s.LineStyle();
    srand((unsigned) time(0));

    vector<string> adjetivos = {"brilhante", "rápido", "lindo", "tranquilo", "majestoso", "estranho", "assustador", 
                                "desbravador", "intimidador", "tentador"};
    vector<string> substantivos = {"sol","rio", "vento", "mar", "céu", "fogo", "sombra","lua", "terra", "chuva"};
    vector<string> verbos = {"brilha", "corre", "sopra", "ondula", "se estende", "dorme", "morre",  "vive", "voa",
                                "dorme"};

    for(int i = 0; i < 3; i++) {
        int adjIndex = rand() % adjetivos.size();
        int subIndex = rand() % substantivos.size();
        int verbIndex = rand() % verbos.size();
        string subs = substantivos[subIndex];

        if ((subs == substantivos[6]) || (subs == substantivos[7]) || (subs == substantivos[8])
        || (subs == substantivos[9])){
            cout << "A " << adjetivos[adjIndex] << " " << subs << " " << verbos[verbIndex] << endl;
        } else { cout << "O " << adjetivos[adjIndex] << " " << subs << " " << verbos[verbIndex] << endl; }
    }
}

void Ativa(){
    dados d;
    nucleo_a::Styles s;
    inicio: 
    cout << "Bem vindo(a)!\nMe chamo " << d.nome << " Prazer em te conhecer, o que deseja fazer agora?" << endl;
    cout << "[1] - Acessar Sistema Neural\n"    << "[2] - Acessar Sistema Quantico\n"
         << "[3] - Poema\n" << "[4] - Acessar sistema Molecular\n" << "[5] - Sair\n-> ";
    int action; cin >> action;
    s.LineStyle();

    if (action == 1){ nucleo_a::menu(); }
    else if (action == 3){ Poema(); }
    else if (action == 5){ cout << "Até breve! Espero ter ajudado! ^^" << endl; }
    else { cout << "Desculpe! Eu não entendi.." << endl; goto inicio; }
    s.LineStyle();
}
#endif