#include <iostream>
#include <cmath>
using namespace std;

// Definindo uma matriz de memória para a IA e variáveis de controle
int memoria_IA[4][4], i, j;

// Função para ensinar a matriz à IA
int ensinar_matriz() {
    // Obtendo o vetor
    int vetor[4];
    for (i = 0; i < 4; i++) {
        cout << "Envie o elemento " << i << " do vetor para aprendizado: ";
        cin >> vetor[i];
    }

    // Aprendendo a matriz com o vetor
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            memoria_IA[i][j] += vetor[i] * vetor[j];
        }
    }

    // Exibindo a construção da matriz no console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << memoria_IA[i][j] << "|";
        }
        cout << '\n';
    }

    return 0;
}

// Função para verificar se a IA reconhece um vetor
int checar_matriz() {
    int vetor[4], matriz_vetor[4], numerador, auxiliar1, auxiliar2;
    double resposta_IA;

    numerador = 0;
    auxiliar1 = 0;
    auxiliar2 = 0;

    // Obtendo o vetor para verificação
    for (i = 0; i < 4; i++) {
        cout << "Envie o elemento " << i << " do vetor para checagem: ";
        cin >> vetor[i];
    }

    // Obtendo a resposta da IA
    for (i = 0; i < 4; i++) {
        matriz_vetor[i] = memoria_IA[i][0] * vetor[i];
        for (j = 1; j < 4; j++) {
            matriz_vetor[i] += memoria_IA[i][j];
        }
    }
    
    // Obtendo a qualidade da resposta
    for (i = 0; i < 4; i++) {
        numerador += matriz_vetor[i] * vetor[i];

        auxiliar1 += matriz_vetor[i] * matriz_vetor[i];
        auxiliar2 += vetor[i] * vetor[i];
    }

    // Calculando a resposta da IA com base na similaridade de cosseno
    resposta_IA = cos((numerador / (sqrt(auxiliar1) * sqrt(auxiliar2))));
    cout << "Resposta da IA é: " << resposta_IA << "\n";

    return 0;
}

// Função principal
int main() {
    // Construindo a matriz
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            memoria_IA[i][j] = 0;
        }
    }

    // Exibindo a construção da matriz no console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << memoria_IA[i][j] << "|";
        }
        cout << '\n';
    }

    int menu = 1;
    while (menu == 1) {
        int escolha;
        cout << "Pressione 1 para ensinar a IA. \n";
        cout << "Pressione 2 para checar se a IA reconhece. \n";
        cout << "Pressione 3 para sair. \n";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                ensinar_matriz();
                break;
            };
            case 2: {
                checar_matriz();
                break;
            };
            case 3: {
                menu = 0;
            };
            break;
        };  
    };

    return 0;
}

