#include <iostream>
#include <string>
using namespace std;

void imprime(string *mat, int nl) {
    for(int i = 0; i < nl; i++){
        cout << mat[i] << "\n";
    }
}

void atear_fogo(int nl, int nc, string *mat, int l, int c){
    if(l > nl-1 || l < 0){
        return;
    }else if(c > nc || c < 0){
        return;
    }else if(mat[l][c] == '.'){
        return;
    }else{
        mat[l][c] = 'o';

        if(mat[l][c - 1] == '#'){
            atear_fogo(nl, nc, mat, l, c - 1);
        }
        if(mat[l][c + 1] == '#'){
            atear_fogo(nl, nc, mat, l, c + 1);
        }
        if(l + 1 < nl && mat[l - 1][c] == '#'){
            atear_fogo(nl, nc, mat, l + 1, c);
        }if(l - 1 >= 0 && mat[l - 1][c] == '#'){
            atear_fogo(nl, nc, mat, l - 1, c);
        }
    }
}

int main(){
    int nl = 0;
    int nc = 0;
    int lfire = 0;
    int cfire = 0;

    cin >> nl >> nc >> lfire >> cfire;

    string* mat = new string[nl];

    for(int i{0}; i < nl; i++){
        string line;
        cin >> line;
        mat[i] = line;
    }
    atear_fogo(nl, nc, mat, lfire, cfire);
    imprime(mat, nl);
    delete[] mat;
}