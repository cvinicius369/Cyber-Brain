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
    Neuronio(double axonio, double bias) : limiar(axonio), bias(bias) {} // construtor da classe
    double feedforward(double axonio) { return axonio * axonio + bias; } // funcao d ativacao

    double alteralimiar(double dado)  { this->limiar = limiar + dado; return this->limiar; }

    void treinar(double entrada, double alvo) {     // funcao que treina o neuronio
        double saida = feedforward(entrada);        // ativa o neuronio e armazena a saida dele
        double erro = alvo - saida;                 // Calcula o erro

        // Ajusta o limiar e o bias usando o gradiente descendente
        limiar += 0.1 * erro * entrada;             // os digitos em double sao as taxas de aprendizado
        bias += 0.1 * erro;

        cout << "Peso -> " << limiar << "\nBias -> " << bias << endl;   // mostrando o peso e o bias
        cout << "Resultado: " << entrada * limiar + bias << endl;       // mostrando a saida
    }

};
class RedeNeural {
    Neuronio neuronio1, neuronio2, neuronio_saida;

public:
    RedeNeural(double w1, double b1, double w2, double b2, double ws, double bs) : neuronio1(w1, b1), neuronio2(w2, b2), neuronio_saida(ws, bs) {}

    double feedforward(double x) {
        double saida_neuronio1 = neuronio1.feedforward(x);
        double saida_neuronio2 = neuronio2.feedforward(x);

        double soma = saida_neuronio1 + saida_neuronio2;
        double saida_rede = neuronio_saida.feedforward(soma);

        return saida_rede;
    }
    void treinar(vector<double> entradas, vector<double> alvos) {
        for (int i = 0; i < entradas.size(); i++) {
            double entrada = entradas[i];
            double alvo = alvos[i];

            // Treina cada neurônio na rede
            neuronio1.treinar(entrada, alvo);
            neuronio2.treinar(entrada, alvo);

            neuronio_saida.treinar(neuronio1.feedforward(entrada) + neuronio2.feedforward(entrada), alvo);
        }
    }
};
void LimiarDeAtivacao(double axonio) {
    if ((axonio > 0.0) && (axonio < 2.0)) {
        double w1, b1, w2, b2, ns, bs, x;
        int decisao;

        cout << "Informe o valor de entrada para Neuronio-1: "; cin >> w1;      // definindo peso do neuronio 1
        cout << "Agora o valor alvo para Neuronio-1: ";         cin >> b1;      // definindo bias do neuronio 1
        cout << "Agora valor de entrada do Neuronio-2: ";       cin >> w2;      // peso do neuronio 2
        cout << "Agora o valor alvo do Neuronio-2: ";           cin >> b2;      // bias do neuornio 2
        cout << "Valor de entrada do Neuronio de Saida: ";      cin >> ns;      // peso do neuronio de saida
        cout << "Valor alvo do Neuronio de Saida: ";            cin >> bs;      // bias do neuronio de saida
        cout << "Agora informe qual o valor de x: ";            cin >> x;       // valor de x

        RedeNeural sinapse1(w1, b1, w2, b2, ns, bs);

        vector<double> entradas = { 1, 2, 3, 4, 5 };
        vector<double> alvos = { 1, 4, 9, 16, 25 };

        for (int i = 0; i <= 3; i++) {                                                        // funcao for para que o treinamento seja repetido até que tenha os valores ideais
            cout << "Alvos: " << alvos[0] << ", " << alvos[1] << ", " << alvos[2] << ", " << alvos[3] << ", " << alvos[4];
            sinapse1.treinar(entradas, alvos);
        }

        sinapse1.feedforward(x);
        cout << "A saida da rede neural para x=" << x << " e: " << sinapse1.feedforward(x) << endl;     //6 é o valor informado para a rede, o retorno deve ser proximo de 36
    }
    else {
        cout << "Neuronio em Repouso!" << endl << "Recuperando Limiar" << endl;
        axonio -= 0.1;
        LimiarDeAtivacao(axonio);
    }
}

class Styles{
    public:
        void LineStyle(){
            cout << "---------------------------------------------------------------------------" << endl;
        }
        void BannerNeural(){
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "///////////////////////////// SISTEMA NEURAL /////////////////////////////" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
};

int main(int argc, char** argv) {
    Styles s;
    int action;

    cout << "[1] - Sistema Neural \n->"; cin >> action;
    s.BannerNeural();
    if (action == 1) {
        double axonio;

        cout << "Informe o valor do estimulo: "; cin >> axonio;
        LimiarDeAtivacao(axonio);
    }

    system("pause");
    return 0;
}
