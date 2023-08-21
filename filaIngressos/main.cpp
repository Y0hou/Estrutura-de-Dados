#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int n;

    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss;

    ss << line;
    vector<int> vet;

    int aux;
    while(ss >> aux){
        vet.push_back(aux);
    }

    int m; 

    cin >> m;   
    cin.ignore();

    string out;
    getline(cin, out);

    stringstream ssOut;
    ssOut << out;

    while(ssOut >> aux){
        for(int i{0}; i < (int)vet.size(); i++){
            if(aux == vet[i]){
                vet.erase(vet.begin() + i);
            }
        }
    }

    for(int i{0}; i < (int)vet.size(); i++){
        cout << vet[i] << " ";
    }

    cout << endl;
}