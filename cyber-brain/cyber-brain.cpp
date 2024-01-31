//Prototipo do projeto CYBER-BRAIN
#include <iostream>          // biblioteca padrao do sistema do c++
#include <string>            // biblioteca que permite o uso de strings
#include <random>            // biblioteca para ajudar a criar numeros randomicos/aleatorios
#include <vector>            // biblioteca que permite o uso de vetores e algebra linear
#include <ctime>             // biblioteca que permite manipular o tempo
#include <cmath>             // biblioteca que permite fazer equacoes matematicas complexas
using namespace std;

//-----------------------------------------------Elementos
void Estilo() {                                                           // funcao para ajudar a entender o software
    cout << "----------------------------------------------------------------------------------------------" << endl;
}
/*
--->> Escala Quantica
*/
//-----------------------------------------------Tabela Periodica
string elementos[] = {
        "Hidrogenio", "Deuterio", "Tritio",                              // Hidrogenio e seus isotopos
        "Helio", 
        "Litio"
    };
//------------------------------------Genericos
class AtomoGeral {
private:
    int nucleo, massa = 0, carga_positiva = 0, carga_negativa = 0, elemento = 0;              // Definidos os atributos do atomo
public:
    int getNucleo() { return nucleo; }                                                        // Obtendo dados do nucleo
    int getMassa() { return massa; }                                                          // Obtendo a massa do atomo
    int getCargaP() { return carga_positiva; }                                                // Obtendo a carga positiva (proton)
    int getCargaN() { return carga_negativa; }                                                // Obtendo a carga negativa (eletron)
    int getElemento() { return elemento; }                                                    // Obtendo o elemento
    int AlteraNucleo(int dado) { this->nucleo = dado; return this->nucleo; }                  // Alterando valor do nucleo
    int AlteraMassa(int dado) { this->massa = dado; return this->massa; }                     // Alterando valor da massa
    int AlteraCargaP(int dado) { this->carga_positiva = dado; return this->carga_positiva; }  // Alterando valor da carga positiva
    int AlteraCargaN(int dado) { this->carga_negativa = dado; return this->carga_negativa; }  // Alterando valor da carga negativa
    int AlteraElemento(int dado) { this->elemento = dado; return this->elemento; }            // Alterando o elemento
};
class Elemento {
private:
    int n_eletrons = 0, n_protons = 0, n_neutrons = 0, massa_total = 0;                     // Definidos os atributos do elemento
    string name;
public:
    // Funcoes para obter valores
    int getEletrons() { return n_eletrons; }                                                // Obtendo os eletrons do elemento
    int getProtons() { return n_protons; }                                                  // Obtendo os protons do elemento
    int getNeutrons() { return n_neutrons; }                                                // Obtendo os neutrons do elemento
    int getMassa() { return massa_total; }                                                  // Obtendo a massa total do elemento
    string getNameElemento() { return name; }                                               // Obtendo o nome do elemento
    void AlteraName(const string& novo) { name = novo; }                                    // Alterando o nome do elemento
    int AlteraMassaTotal(int dado) { this->massa_total = dado; return this->massa_total; }  // Alterando a massa total
    int AlteraProton(int dado) { this->n_protons = dado; return this->n_protons; }          // Alterando a quantidade de protons
    int AlteraEletron(int dado) { this->n_eletrons = dado; return this->n_eletrons; }       // Alterando a quantidade de eletrons
    int AlteraNeutron(int dado) { this->n_neutrons = dado; return this->n_neutrons; }       // Alterando a quantidade de neutrons
};
//--------------------------------------------------| Maquinas criadoras
void ApresentaDadosAtomo(AtomoGeral* atomo) {
    cout << "Particulas criadas" << endl;
    printf("Numero de Protons: %d \n", atomo->getCargaP());         // Apresentando proton
    printf("Numero de Neutrons: %d \n", atomo->getMassa());         // Apresentando neutron
    printf("Numero de Eletrons: %d \n", atomo->getCargaN());        // Apresentando eletron   
}
void ApresentaDadosElemento(Elemento elemento) {                              // Funcao que apresenta os dados dos
    cout << "Numero de Protons: " << elemento.getProtons() << endl;           // Apresentando protons
    cout << "Numero de Neutrons: " << elemento.getNeutrons() << endl;         // Apresentando neutrons
    cout << "Numero de Eletrons: " << elemento.getEletrons() << endl;         // Apresentando eletrons
    cout << "Massa total do nucleo: " << elemento.getMassa() << endl;         // Apresentando massa total do nucleo 
}
void CiraElemento() {                                          // Funcao que cria elementos de acordo com os desejos do usuario
    int element;
    cout << "Escolha o elemento:" << endl;
    cout << "[1] Hidrogenio\n[2] Deuterio\n[3] Tritio\n[4] Helio\n[5] Litio\nR= ";
    cin >> element;
    if (element == 1) {
        Elemento hidrogenio;                                                                // Cria elemento Hidrogenio (H)
        hidrogenio.AlteraEletron(hidrogenio.getEletrons() + 1); hidrogenio.AlteraProton(hidrogenio.getProtons() + 1);
        hidrogenio.AlteraNeutron(hidrogenio.getNeutrons() + 1); hidrogenio.AlteraMassaTotal(hidrogenio.getProtons() + hidrogenio.getNeutrons());
        hidrogenio.AlteraName("Hidrogenio");
        cout << "Atomo: Hidrogenio" << endl;
        ApresentaDadosElemento(hidrogenio);
    }
    else if (element == 2) {
        Elemento deuterio;                                                                  // Cria elemento Deuterio (H^2)
        deuterio.AlteraEletron(deuterio.getEletrons() + 1); deuterio.AlteraProton(deuterio.getProtons() + 1);
        deuterio.AlteraNeutron(deuterio.getNeutrons() + 2); deuterio.AlteraMassaTotal(deuterio.getProtons() + deuterio.getNeutrons());
        deuterio.AlteraName("Deuterio");
        cout << "Atomo: Deuterio" << endl;
        ApresentaDadosElemento(deuterio);
    }
    else if (element == 3) {
        Elemento tritio;                                                                     // Cria elemento Tritio (H^3)
        tritio.AlteraEletron(tritio.getEletrons() + 1); tritio.AlteraProton(tritio.getProtons() + 1);
        tritio.AlteraNeutron(tritio.getNeutrons() + 2); tritio.AlteraMassaTotal(tritio.getProtons() + tritio.getNeutrons());
        tritio.AlteraName("Tritio");
        cout << "Atomo: Tritio" << endl;
        ApresentaDadosElemento(tritio);
    } // Mais elementos
}
void CriaAtomo(AtomoGeral* atomo) {
    int dado = 0, repeticoes = 0;
    srand(time(NULL));
    while (repeticoes <= 2) {                                       // Gerando quantidade determinada de particulas
        dado = rand() % 3 - 1;                                      // Funcao gerando numeros aleatorios entre -1 e 1 que vao determinar a particula
        if (dado > 0) {
            atomo->AlteraCargaP(atomo->getCargaP() + 1);            // Alterando/criando o valor do atributo do atomo (no caso é a carga positiva
            cout << "Proton adicionado ao atomo" << endl;           // Confirmando a criação da particula e a atribuição da mesma ao atomo
        }
        else if (dado == 0) {
            atomo->AlteraMassa(atomo->getMassa() + 1);              // Alterando/criando neutron e atribuindo ele ao atomo
            cout << "Neutron adicionado ao atomo" << endl;          // Confirmando a criação do neutron
        }
        else {
            atomo->AlteraCargaN(atomo->getCargaN() - 1);            // Inserindo particula ao atomo
            cout << "Eletron adicionado ao atomo" << endl;          // Confirmando adição
        }
        repeticoes = repeticoes + 1;                                // Controlando o numero de repetições
    }
    if (atomo->getCargaP() > 0) {
        cout << "Atomo criado com sucesso!" << endl;                // mensagem printada ao criar o atomo automaticamente
    }
    else {
        cout << "Atomo não criado [Precisa de Protons]" << endl;    // quando não ha nenhum proton sera impressa essa mensagem
    }
    if (atomo->getCargaP() == 1) {                                                   // auto definicao dos atomos onde dependendo das suas particulas um elemento eh criado
        if (atomo->getMassa() == 0) {
            Elemento hidrogenio;                                                     // modelo padrao para os outros elementos, o objeto com o nome do elemento eh criado
            hidrogenio.AlteraName("Hidrogenio");                                     // o nome do elemento eh atribuido    
            hidrogenio.AlteraEletron(atomo->getCargaN());                            // a quantidade de eletrons eh atribuida tambem
            hidrogenio.AlteraProton(atomo->getCargaP());                             // a quantidade de protons
            hidrogenio.AlteraNeutron(atomo->getMassa());                             // a quantidade de neutrons
            hidrogenio.AlteraMassaTotal(atomo->getCargaP() + atomo->getMassa());     // o peso do nucleo
            atomo->AlteraElemento(atomo->getElemento() + 1);                         // atribuindo o elemento ao atomo criado
            ApresentaDadosAtomo(atomo);                                              // apresentando os dados do novo elemento
            delete atomo;                                                            // delete o atomo generico usado para criar o elemento
            cout << "Atomo: Hidrogenio" << endl;                                     // informa o nome do elemento
        }
        else if (atomo->getMassa() == 1) {                                           // o mesmo ocorre para essas situaçoes onde o numero e tipo de particulas variam
            Elemento deuterio; deuterio.AlteraName("Deuterio");
            deuterio.AlteraEletron(atomo->getCargaN()); deuterio.AlteraProton(atomo->getCargaP());
            deuterio.AlteraNeutron(atomo->getMassa()); deuterio.AlteraMassaTotal(atomo->getCargaP() + atomo->getMassa());
            atomo->AlteraElemento(atomo->getElemento() + 1); ApresentaDadosAtomo(atomo); delete atomo;
            cout << "Atomo: Deuterio" << endl;
        }
        else if (atomo->getMassa() == 2) {
            Elemento tritio; tritio.AlteraName("Tritio");
            tritio.AlteraEletron(atomo->getCargaN()); tritio.AlteraProton(atomo->getCargaP());
            tritio.AlteraNeutron(atomo->getMassa()); tritio.AlteraMassaTotal(atomo->getCargaP() + atomo->getMassa());
            atomo->AlteraElemento(atomo->getElemento() + 1); ApresentaDadosAtomo(atomo); delete atomo;
            cout << "Atomo: Tritio" << endl;
        }
    }
    else if ((atomo->getCargaP() == 2)) {
        Elemento helio; helio.AlteraName("Helio");
        helio.AlteraEletron(atomo->getCargaN()); helio.AlteraProton(atomo->getCargaP());
        helio.AlteraNeutron(atomo->getMassa()); helio.AlteraMassaTotal(atomo->getCargaP() + atomo->getMassa());
        atomo->AlteraElemento(atomo->getElemento() + 2); ApresentaDadosAtomo(atomo); delete atomo;
        cout << "Atomo: Helio" << endl;
    }
    else if (atomo->getCargaP() == 3) {
        Elemento litio; litio.AlteraName("Litio");
        litio.AlteraEletron(atomo->getCargaN()); litio.AlteraProton(atomo->getCargaP());
        litio.AlteraNeutron(atomo->getMassa()); litio.AlteraMassaTotal(atomo->getCargaP() + atomo->getMassa());
        atomo->AlteraElemento(atomo->getElemento() + 3); ApresentaDadosAtomo(atomo); delete atomo;
        cout << "Atomo: Litio" << endl;
    }
}

//-------------------------------------------------------------------| Nivel Molecular
class Molecula {                                                   // classe molecula onde contem os atributos de uma molecula
    private:
        int qtd_elementos;
    public:
        int getElementos() { return qtd_elementos; }
    };

class GeraMolecul{

};

//-------------------------------------------------------------------| Neuronio
class Neuronio {
    double peso, bias;                                                        // peso define o quao importante um neuronio sera e bias balanceia a equacao

    public:
        Neuronio(double peso, double bias) : peso(peso), bias(bias) {}        // construtor permitindo o manuseio das variaveis
                                                                              // Função linear
        double feedforward(double entrada) { return entrada * peso + bias; }

        void treinar(double entrada, double alvo) {
            double saida = feedforward(entrada);
            double erro = alvo - saida;                                       // Calcula o erro

                                                                              // Ajusta o peso e o bias usando o gradiente descendente
            peso += 0.1 * erro * entrada;                                     // os digitos em double sao as taxas de aprendizado
            bias += 0.1 * erro;

            cout << "Peso -> " << peso << "\nBias -> " << bias << endl;       // mostrando o peso e o bias
            Estilo();
            cout << "Resultado: " << entrada * peso + bias << endl;           // mostrando a saida
            Estilo();
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

int main(int argc, char** argv) {
    int decision, decision_quantic;
    cout << "[1] Sistema Quantico\n[2] Rede Neural\n-> ";
    cin >> decision;
    Estilo();
    if (decision == 1) {                                                          // iniciando sistema quantico
        cout << "////////////////////////////////// Acessando Sistema Quantico ///////////////////////////////" << endl; Estilo();
        AtomoGeral* atomo = new AtomoGeral();                                     // criando atomo generico usando ponteiros
        atomo->getNucleo();                                                       // obtendo informacoes do nucleo
        CriaAtomo(atomo); Estilo();                                               // criando atomo automaticamente gerando 3 particulas aleatorias
        cout << "Sistema Quantico Nivel Atomico: Funcional" << endl; Estilo();    // confirmando funcionamento do sistema quantico
        cout << "Criar novo atomo? [1]Sim/[2]Nao" << endl;
        cin >> decision_quantic;
        if (decision_quantic == 1) {
            CiraElemento();                                                       // funcao para criar novo elemento com base no atomo criado por particulas
        }
    }
    else if (decision == 2) {
        int opcoes;
        cout << "/////////////////////////////////// Acessando Sistema Neural ///////////////////////////////" << endl; Estilo();
        cout << "[1] Ativar Neuronios\n[2] Iniciar Treinamento\n-> ";
        cin >> opcoes;

        if (opcoes == 1) {
            bool cont = true;
            while (cont == true) {
                double w1, b1, w2, b2, ws, bs;
                int decisao;
                                                                                  
                cout << "Informe o valor de entrada para Neuronio-1: "; cin >> w1;      // definindo peso do neuronio 1
                cout << "Agora o valor alvo para Neuronio-1: ";         cin >> b1;      // definindo bias do neuronio 1
                cout << "Agora valor de entrada do Neuronio-2: ";       cin >> w2;      // peso do neuronio 2
                cout << "Agora o valor alvo do Neuronio-2: ";           cin >> b2;      // bias do neuornio 2
                cout << "Valor de entrada do Neuronio de Saida: ";      cin >> ws;      // peso do neuronio de saida
                cout << "Valor alvo do Neuronio de Saida: ";            cin >> bs;      // bias do neuronio de saida
                Estilo();

                RedeNeural redeNeural(w1, b1, w2, b2, ws, bs);                          // instanciando rede neural

                // Testa a rede neural
                cout << "A saida da rede neural para x=6 e: " << redeNeural.feedforward(6) << endl;  //6 é o valor informado para a rede, o retorno deve ser proximo de 36
                cout << "Continuar?\n[1]Sim\n[2]Nao\n-> "; cin >> decisao;
                if (decisao == 2) { cont = false; }                                                  // condicional que define a continuidade do codigo
                Estilo();
            }
        } else if (opcoes == 2) {
                                                                                             // Treina a rede neural
            double w1 = 0, b1 = 0, w2 = 0, b2 = 0, ws = 0, bs = 0;

            RedeNeural redeNeural(w1, b1, w2, b2, ws, bs);
                                                                                             // Dados de treinamento
            vector<double> entradas = { 1, 2, 3, 4, 5 };
            vector<double> alvos = { 1, 4, 9, 16, 25 };

            for (int i = 0; i <= 3; i++) {                                                  // funcao for para que o treinamento seja repetido até que tenha os valores ideais
                cout << "Alvos: " << alvos[0] << ", " << alvos[1] << ", " << alvos[2] << ", " << alvos[3] << ", " << alvos[4];
                redeNeural.treinar(entradas, alvos);
            }
        }
    }
    system("pause");
    return 0;
}