#include <sstream> 
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void vet(vector<int> &v, int tam){
    if(tam == 1){
        cout << v[0] << " ";
    }else {
        vet (v, tam - 1);
        cout << v[tam - 1] << " ";
    }
}

void rvet(vector<int> &v, int tam){
    if(tam == 1){
        cout << v[0] << " ";
    }else { 
        cout << v[tam - 1] << " ";
        rvet(v, tam - 1);
    }
}

int sum(vector<int> &v, int tam){
    int s{0};

    if(tam == 1){
        return v[0];
    }else {
        s = v[tam - 1] + sum(v, tam - 1);
        return s;
    }
}

int mult(vector<int> &v, int tam){
    int m{0};

    if(tam == 1){
        return v[0];
    }else {
        m = v[tam - 1] * mult(v, tam - 1);
        return m;
    }
}

void inv(vector<int> &v, int i, int f){
    if(i < f){
        int aux = v[i];
        v[i] = v[f];
        v[f] = aux;

        inv(v, i + 1, f - 1);
    }
}

int min(vector<int> &v, int tam){
    if(tam == 1){
        return 0;
    }else {
        int aux = min(v, tam - 1);
        if(v[tam - 1] > aux){
            return aux;
        }else {
            return v[tam - 1];
        }
    }
}

int main(){
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    
    vector<int> v;
    
    int value;
    while(ss >> value){
        v.push_back(value);
    }

    cout << "vet : [ ";

    vet(v, (int)v.size());

    cout << "]" << endl;
    cout << "rvet: [ ";

    rvet(v, (int)v.size());

    cout << "]" << endl;
    cout << "sum : " << sum(v, (int)v.size()) << endl;
    cout << "mult: " << mult(v, (int)v.size()) << endl;
    cout << "min : " << min(v, (int)v.size()) << endl;
    cout << "inv : [ ";

    inv(v, 0, (int)v.size()-1);
    vet(v, (int)v.size());
    
    cout << "]" << endl;
}