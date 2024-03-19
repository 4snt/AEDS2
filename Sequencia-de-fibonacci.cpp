#include<iostream>

using namespace std;

int sequenciadefibonacci(int n, int segundonanterior=0, int nanterior=1){
    if (n==0){
        return segundonanterior;
    }
    cout << "N:" << n-1 <<" da sequencia e:" <<segundonanterior+nanterior <<"\n";
    return sequenciadefibonacci(n-1, nanterior, segundonanterior+nanterior);
}

int main(){
    int nsequencias;
    cout << "Quantas sequencias deseja realizar?\n";
    cin >> nsequencias;
    cout << "Sequencia de fibonacci:\n";
    sequenciadefibonacci(nsequencias);
    return 0;
}