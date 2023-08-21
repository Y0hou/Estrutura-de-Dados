#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>

class Stack{
private:
    Node<T>* m_top // ponteiro para o topo da pilha
    int m_size;

public:
    //construtor cria pilha vazia
    Stack(){
        m_top = nullptr;
        m_size = 0;
    } 

    //verifica se pilha vazia
    bool empty(){
        return m_top == nullptr;
    }

    //retorna o tamanho da pilha
    int size(){
        return m_size;
    }
    //retorna valor do elemento no topo
    //se pilha for vazia, lança excecao
    T& top(){
        if(m_top == nullptr){
            throw std::runtime_error("stack underflow")
        }

        return m_top -> value;
    }
    //inserir na pilha
    void push(const T& val){
        Node<T>* aux = new Node(val, m_top);
        m_top = aux;
        m_size++;
    }

    void pop() {
        if(m_size != 0) {
            Node<T>* aux = m_top;
            m_top = m_top -> next;
            aux -> next = nullptr;
            delete aux;
            m_size--;
        }
         
    }

    tilStack() {
        delete m_top;
    }
    //rem
};


#endif