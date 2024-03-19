#include <iostream>
#include <cmath>
using namespace std;

// Definindo uma matriz de memória para a IA e variáveis de controle
int iaMemory[4][4], i, j;

// Função para ensinar a matriz à IA
int teachMatrix() {
    // Obtendo o vetor
    int vetor[4];
    for (i = 0; i < 4; i++) {
        cout << "Envie o elemento " << i << " do vetor para aprendizado: ";
        cin >> vetor[i];
    }

    // Aprendendo a matriz com o vetor
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            iaMemory[i][j] += vetor[i] * vetor[j];
        }
    }

    // Exibindo a construção da matriz no console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << iaMemory[i][j] << "|";
        }
        cout << '\n';
    }

    return 0;
}

// Função para verificar se a IA reconhece um vetor
int check() {
    int vetor[4], matrixVetor[4], numerator, aux1, aux2;
    double iaResponse;

    numerator = 0;
    aux1 = 0;
    aux2 = 0;

    // Obtendo o vetor para verificação
    for (i = 0; i < 4; i++) {
        cout << "Envie o elemento " << i << " do vetor para checagem: ";
        cin >> vetor[i];
    }

    // Obtendo a resposta da IA
    for (i = 0; i < 4; i++) {
        matrixVetor[i] = iaMemory[i][0] * vetor[i];
        for (j = 1; j < 4; j++) {
            matrixVetor[i] += iaMemory[i][j];
        }
    }
    
    // Obtendo a qualidade da resposta
    for (i = 0; i < 4; i++) {
        numerator += matrixVetor[i] * vetor[i];

        aux1 += matrixVetor[i] * matrixVetor[i];
        aux2 += vetor[i] * vetor[i];
    }

    // Calculando a resposta da IA com base na similaridade de cosseno
    iaResponse = cos((numerator / (sqrt(aux1) * sqrt(aux2))));
    cout << "Resposta da IA é: " << iaResponse << "\n";

    return 0;
}

// Função principal
int main() {
    // Construindo a matriz
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            iaMemory[i][j] = 0;
        }
    }

    // Exibindo a construção da matriz no console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << iaMemory[i][j] << "|";
        }
        cout << '\n';
    }

    int menu = 1;
    while (menu == 1) {
        int choice;
        cout << "Pressione 1 para ensinar a IA. \n";
        cout << "Pressione 2 para checar se a IA reconhece. \n";
        cout << "Pressione 3 para sair. \n";
        cin >> choice;

        switch (choice) {
            case 1: {
                teachMatrix();
                break;
            };
            case 2: {
                check();
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
