#include<iostream>
using namespace std;
int main(){
    int NumFatorial, i=1;
    cout << "Digite o numero a ser feito o fatorial:\n";
    cin >> NumFatorial;
    for (NumFatorial; NumFatorial > 1; NumFatorial--) {i *=NumFatorial;}
    cout << "O resultado do fatorial é: " << i << "\n";
    return 0;
}