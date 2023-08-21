#include <iostream> 

using namespace std;

int fib(int& n){
    int fib {1};
    int aux {1};

    if(n <= 1){
        return n;
    }

    for(int i {2}; i < n; i++){
        int aux2 = fib;

        fib = fib + aux;
        aux = aux2;
    }

    return fib;
}

int main(){

    int n {0};
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}

