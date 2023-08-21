#include <iostream>
#include <queue>

using namespace std;

int main(){
    char eq = 'A';
    queue<char> fila;

    while(eq != 'Q'){
        fila.push(eq);
        eq++;
    }

    for(int i{0}; i < 15; i++){
        int eq1;
        int eq2;

        cin >> eq1 >> eq2;

        if(eq1 > eq2){
            fila.push(fila.front());
            fila.pop();
            fila.pop();
        }else if(eq1 < eq2){
            fila.pop();
            fila.push(fila.front());
            fila.pop();
        }
    }

    cout << fila.front() << endl;
}