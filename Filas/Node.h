#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T value;  //valor a ser guardado
    Node* next;   //ponteiro para o proximo da fila

    Node(const T& val, Node* nextPtr) {
        value = val;
        next = nextPtr;
    }

    ~Node() {
        delete next;
    }
};

#endif