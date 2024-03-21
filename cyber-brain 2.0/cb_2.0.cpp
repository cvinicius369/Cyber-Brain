#include <iostream>     // biblioteca excenssial para o bom funcionamento do software                           
#include <cmath>        // biblioteca que ajuda a realizar calculos matematicos complexos
#include <vector>       // biblioteca que ajuda a manipular vetores e matrizes
#include <string>       // bibliotexa que permite o uso de strings
#include <ctime>        // biblioteca que permite a manipulacao do tempo
using namespace std;    // espaco que permite o uso de funcoes sem mencionar o termo "std::nome_da_funcao"

class Neuronio {
private:
    double limiar, bias;     // o limiar tem o papel do peso que define o quao importante um neuronio eh
public:
   Neuronio(double axonio1, double axonio2, double axonio3, double bias) : limiar(axonio1), bias(bias) {} // construtor da classe
    double feedforward(double axonio1, double axonio2, double axonio3) {return axonio1 * limiar + axonio2 * axonio2 + axonio3 * axonio3 + bias;} // funcao d ativacao

    double alteralimiar(double dado)  { this->limiar = limiar + dado; return this->limiar; }

    void treinar(double x1, double x2, double x3, double alvo) {     // funcao que treina o neuronio
        double saida = feedforward(x1, x2, x3);  // Ativa o neurônio e armazena a saída
        double erro = alvo - saida;              // Calcula o erro

        // Ajusta o limiar e o bias usando o gradiente descendente
        limiar += 0.1 * erro * (x1 + x2 + x3);   // Taxas de aprendizado multiplicadas pela soma das entradas
        bias += 0.1 * erro;

        cout << "Peso -> " << limiar << "\nBias -> " << bias << endl;   // Mostra o peso e o bias
        cout << "Resultado: " << (x1 * limiar) + (x2 * x2) + (x3 * x3) + bias << endl;  // Mostra a saída
    }

};
class RedeNeural {
    Neuronio neuronio1, neuronio2, neuronio_saida;

public:
    RedeNeural(double w1, double w2, double w3, double b1, double b2, double bs)
        : neuronio1(w1, w2, w3, b1), neuronio2(w1, w2, w3, b2), neuronio_saida(w1, w2, w3, bs) {}

    double feedforward(double x1, double x2, double x3) {
        double saida_neuronio1 = neuronio1.feedforward(x1, x2, x3);
        double saida_neuronio2 = neuronio2.feedforward(x1, x2, x3);
        double soma = saida_neuronio1 + saida_neuronio2;
        double saida_rede = neuronio_saida.feedforward(soma, soma, soma);
        return saida_rede;
    }
    void treinar(vector<double> entradas1, vector<double> entradas2, vector<double> entradas3, vector<double> alvos) {
        for (int i = 0; i < entradas1.size(); i++) {
            double entrada1 = entradas1[i];
            double entrada2 = entradas2[i];
            double entrada3 = entradas3[i];
            double alvo = alvos[i];

            // Treina cada neurônio na rede
            neuronio1.treinar(entrada1, entrada2, entrada3, alvo);
            neuronio2.treinar(entrada1, entrada2, entrada3, alvo);

            // Calcula a saída da rede neural considerando as três entradas
            double saida_rede = neuronio_saida.feedforward(entrada1, entrada2, entrada3);
            neuronio_saida.treinar(saida_rede, saida_rede*2, saida_rede*3, alvo);
    }
}
};
void LimiarDeAtivacao(double axonio) {
    if ((axonio > 0.0) && (axonio < 2.0)) {
        double w1, b1, w2, b2, ns, bs, x1, x2, x3;
        int decisao;

        cout << "Informe o valor de entrada para Neuronio-1: "; cin >> w1;      // definindo peso do neuronio 1
        cout << "Agora o valor alvo para Neuronio-1: ";         cin >> b1;      // definindo bias do neuronio 1
        cout << "Agora valor de entrada do Neuronio-2: ";       cin >> w2;      // peso do neuronio 2
        cout << "Agora o valor alvo do Neuronio-2: ";           cin >> b2;      // bias do neuornio 2
        cout << "Valor de entrada do Neuronio de Saida: ";      cin >> ns;      // peso do neuronio de saida
        cout << "Valor alvo do Neuronio de Saida: ";            cin >> bs;      // bias do neuronio de saida
        cout << "Agora informe qual o valor de x1: ";           cin >> x1;       // valor de x
        cout << "Agora informe qual o valor de x2: ";           cin >> x2;
        cout << "Agora informe qual o valor de x3: ";           cin >> x3;

        RedeNeural sinapse1(w1, b1, w2, b2, ns, bs);

        vector<double> entradas1 = { 1, 2, 3, 4, 5 };
        vector<double> entradas2 = { 1, 2, 3, 4, 5 };
        vector<double> entradas3 = { 1, 2, 3, 4, 5 };
        vector<double> alvos = { 1, 4, 9, 16, 25 };

        for (int i = 0; i <= 3; i++) {                                                        // funcao for para que o treinamento seja repetido até que tenha os valores ideais
            cout << "Alvos: " << alvos[0] << ", " << alvos[1] << ", " << alvos[2] << ", " << alvos[3] << ", " << alvos[4];
            sinapse1.treinar(entradas1, entradas2, entradas3, alvos);
        }

        sinapse1.feedforward(x1, x2, x3);
        cout << "A saida da rede neural e: " << sinapse1.feedforward(x1, x2, x3) << endl; 
    }
    else {
        cout << "Neuronio em Repouso!" << endl << "Recuperando Limiar" << endl;
        axonio -= 0.1;
        LimiarDeAtivacao(axonio);
    }
}
int main()
{
    double axonio, alvo;
    cout << "Informe o valor do estimulo: "; cin >> axonio;
    LimiarDeAtivacao(axonio);
}
