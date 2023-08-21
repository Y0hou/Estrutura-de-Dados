#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

Matriz::Matriz(int m, int n) {
	this -> lin = m;
	this -> col = n;
	this -> mat = new int* [n];
	
	for (int i{0}; i < m; i++){
		mat[i] = new int [m];
	}
	
}   

Matriz::~Matriz() {
	for(int i{0}; i < this -> lin; i++){
		delete[] mat[i];
	}

	delete[] mat;

	cout << "matriz liberada" << endl;
}   

int Matriz::linhas() {
	return this -> lin;
} 

int Matriz::colunas() { 
	return this -> col;
}

int Matriz::getValor(int i, int j) {
	return this -> mat[i][j];
} 

void Matriz::setValor(int valor, int i, int j) {
	this -> mat[i][j] = valor;
}

void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
} 

Matriz *Matriz::soma(Matriz& B) {
	Matriz* aux = new Matriz(this -> lin, this -> col);

	if(B.lin == this -> lin && B.col == this -> col){
		for(int i{0}; i < this -> lin; i++){
			for(int j{0}; i < this -> col; j++){
				aux -> mat[i][j] = B.mat[i][j] + this -> mat[i][j];
			}
		}
		return aux;

	}else {
		cout << "nao foi possivel somar" << endl;
		return nullptr;

	}

}

Matriz *Matriz::multiplica(Matriz& B) {
	if(this -> col == B.lin){
		Matriz* aux = new Matriz(this -> lin, B.col);

		for(int i{0}; i < aux -> lin; i++){
			for(int j{0}; j < aux -> col; j++){
				aux -> mat[i][j];
				for(int k{0}; k < this -> lin; k++){
					aux -> mat[i][j] += this -> mat[i][k] * B.mat[k][j];
				}
			}
		}
		return aux;

	}else {
		cout << "nao foi possivel multiplicar" << endl;
		return nullptr;

	}
}