#include <iostream>

using namespace std;

int funcaofatorial(int numFatorial, int result = 1){
    return (numFatorial <= 1) ? result : funcaofatorial(numFatorial - 1, result * numFatorial);
}


int main(){
    int numFatorial;
    cout << "Digite o numero a ser feito o fatorial:\n";
    cin >> numFatorial;
    cout << "O Fatorial do numero é: " << funcaofatorial(numFatorial) << "\n";
    return 0;
}