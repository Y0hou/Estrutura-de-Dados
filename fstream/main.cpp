#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "SparseMatrix.h"

using namespace std;

SparseMatrix* readSparseMatrix(const string& matriz_esparsa){
    ifstream inputFile("matriz_esparsa.txt"); //lendo arquivo

    if(!inputFile.is_open()){ //Lança uma exception 
        throw runtime_error("Erro ao abrir arquvio");
    }

    int x, y; //linhas e colunas
    inputFile >> x >> y; //Alocando 
}


int main(){
    
return 0;   
}