#include <iostream>
#include "CircularList.h"
using namespace std;

void print(const CircularList& lst) {
    for(int i = 0; i < lst.size(); ++i)
        cout << lst[i] << " ";
    cout << endl;
}

void CircularList::clear() {
    if(m_head -> next != m_head) {
        Node* aux = m_head -> next;
        while(aux != m_head){
            Node* del = aux;
            aux = aux -> next;
            delete del;
        }
        m_head -> next = m_head;
        m_size = 0;
    }
}

CircularList::~CircularList() {
    clear();
    delete m_head;
}



int main() {
    CircularList lst;

    for(int i = 1; i <= 9; ++i) 
        lst.push_back(i * 0.5);

    cout << lst.toString() << endl;
}