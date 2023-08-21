#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue {

private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_size;

public:

    Queue();
    //Insere elemnto na fila 
    void push(const T& v);
    //Remove um elemento da fila
    void pop();
    //Retorna se fila esta vazia
    bool empty();
    //Acessa o primeiro elemento da fila
    //se fila vazia lança uma out_of_range exception
    T& front();
    //Acessa o ultimo elemento da fila
    //se fila vazia lança uma out_of_range exception
    T& back();
    //Retorna o numero de elementos na fila
    int size();
    //Construtor de copia
    Queue(const Queue& q);
    //Sobreacarga do operador de atribuiçao
    Queue& operator=(const Queue& q);
    //sobrecarga do operador ==
    bool& operator==(const Queue& q)
};

template <typename T>
Queue<T>::Queue() {
    m_head = m_tail = nullptr;
    m_size = 0;
}

template <typename T>
void Queue<T>::push(const T& v) {
    Node<T>* aux = new Node<T>(v, nullptr);
    
    if(m_size == 0) {
        m_head = m_tail = aux;
    }else {
        m_tail = m_tail -> next = aux;
    }
    m_size++;
}

template <typename T>
void Queue<T>::pop() {
    if(m_size == 0){
        return;
    }
    Node<T> *aux = m_head;
    m_head = m_head -> next;
    aux -> next == nullptr;
    delete aux; 
    if(m_head == nullptr){
        m_tail == nullptr;
    }
}

template <typename T>
bool Queue<T>::empty() {
    return m_size == 0;
}

template <typename T>
T& Queue<T>::front() {
    if(m_size == 0){
        throw std::runtime_error("empty queue");
    }
    return m_head -> value;
}

template <typename T>
T& Queue<T>::back() {
    if(m_size == 0){
        throw std::runtime_error("empty queue");
    }
    return m_tail -> value;
}

//construtor copia
template <typename T>
Queue<T>::Queue(const Queue& q) {
    m_head = m_tail = nullptr;
    m_size = 0;
    Node<T>* aux = q.m_head
    while(aux != nullptr){
        push(aux -> value);
        aux = aux -> next;
    }
}

template <typename T>
Queue<T>::Queue(){
    delete m_head;
}

template <typename T>
bool& Queue<T>::operator==(const Queue& q) const{
    if(m_size != q.m_size){
        return false;
    }

    Node<T>* aux1 = q.m_head;
    Node<T>* aux2 = m_head;

    while(aux1 != nullptr){
        if(aux1 -> value != aux2 -> value){
            return false;
        }else{
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
    }

    return true;
}

#endif





