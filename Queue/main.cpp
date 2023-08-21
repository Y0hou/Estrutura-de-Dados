#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

int main(){
    int i{0};
    cin >> i;
    cin.ignore();

    Queue fila;

    while(i != 0){
        string line;
        getline(cin, line);
        stringstream ss {line};

        int comando;
        ss >> comando;

        switch(comando){
            case 1:
                int value;
                ss >> value;
                fila.push(value);
                break;
            case 2: 
                fila.pop();
                break;
            case 3: 
                cout << fila.first() << endl;
                break;
        }
        i--;
    }
}