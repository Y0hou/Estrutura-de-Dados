#include <iostream>

using namespace std;

void hanoi(int qte, char ini, char aux, char fim){
    if(qte >= 2){
        hanoi(qte - 1, ini, fim, aux);
        cout << ini << " -> " << fim << endl;
        hanoi(qte - 1, aux, ini, fim);
    }else {
        cout << ini << " -> " << fim << endl;
    }
}

int main(){
    int qte;
    cin >> qte;
    hanoi(qte, 'A', 'B', 'C');
    return 0;
}