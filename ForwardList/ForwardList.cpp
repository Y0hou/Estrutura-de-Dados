/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

Item& ForwardList::front() {
    return this -> m_head -> next -> value;
}

const Item& ForwardList::front() const {
    return this -> m_head -> next -> value;
}
    
void ForwardList::push_front(const Item& value) {
    this -> m_head -> next = new Node(value, this -> m_head -> next);
    this -> m_size++;
}

void ForwardList::pop_front() {
    if(this -> m_head -> next != nullptr){
        Node* aux = this -> m_head -> next -> next;
        delete this -> m_head -> next;
        this -> m_head -> next = aux;
        this -> m_size--;
    }
}

Item& ForwardList::back() {
    Node* aux = this -> m_head -> next;

    while(aux -> next != nullptr){
        aux = aux -> next;
    }

    return aux -> value;
}

const Item& ForwardList::back() const {
    Node* aux = this -> m_head -> next;

    while(aux -> next != nullptr){
        aux = aux -> next;
    }

    return aux -> value;
}
    
void ForwardList::push_back(const Item& val) {
    Node* aux = this -> m_head;

    while(aux -> next != nullptr){
        aux = aux -> next;
    }

    aux -> next = new Node(val, nullptr);
    this -> m_size++;
}

void ForwardList::pop_back() {
    if(this -> m_head -> next == nullptr){
        return;
    }else {
        Node* aux = this -> m_head;
    
        while(aux -> next -> next != nullptr){
            aux = aux -> next;
        }

        delete aux -> next;
        aux -> next = nullptr;
        this -> m_size--;
    }
}

void ForwardList::concat(ForwardList& lst) {
    Node* current = this->m_head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = lst.m_head->next;
    lst.m_head->next = nullptr;

    m_size += lst.m_size;
    lst.m_size = 0;
}

void ForwardList::remove(const Item& val) {
    Node* current = m_head;
    while (current->next != nullptr) {
        if (current->next->value == val) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            m_size--;
        } else {
            current = current->next;
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList* copy = new ForwardList;
    Node* current = this -> m_head;
    Node* aux = copy -> m_head;

    while(current -> next != nullptr){
        aux -> next = new Node(current -> next -> value, nullptr);
        aux = aux -> next;
        current = current -> next;
    }

    copy -> m_size = this -> m_size;
    return copy;
}

void ForwardList::appendVector(const std::vector<Item>& vec){
    Node* aux = this -> m_head;

    while(aux -> next != nullptr){
        aux = aux -> next;
    }

    for(int i{0}; i < vec.size(); i++){
        aux -> next = new Node(vec[i], nullptr);
        aux = aux -> next;
    }

    this -> m_size += vec.size();
}

void ForwardList::swap(ForwardList& lst) {
    ForwardList tmp {lst};

    int tmpSize{0};
    tmpSize = this -> m_size;
    this -> m_size = tmp.m_size;
    lst.m_size = tmpSize;

    lst.m_head = this -> m_head;
    this -> m_head = tmp.m_head;
}

bool ForwardList::equals(const ForwardList& lst) const{
    if(this -> m_size != lst.m_size){
        return false;
    }

    Node* current = this -> m_head;
    Node* aux = lst.m_head;

    while(current -> next != nullptr){
        if(current -> next -> value != aux -> next -> value){
            return false;
        }

        current = current -> next;
        aux = aux -> next;
    }

    return true;
}

void ForwardList::reverse() {
    Node* previous = nullptr;
    Node* current = this->m_head->next;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    this->m_head->next = previous;
}

Item& ForwardList::get(int index) {
    if(index < 0 || index > this -> m_size){
        throw std::range_error("index out of range");
    }

    Node* aux = this -> m_head -> next;

    for(int i{0}; i < index; i++){
        aux = aux -> next;
    }

    return aux -> value;
}

const Item& ForwardList::get(int index) const{
    if(index < 0 || index > this -> m_size){
        throw std::range_error("index out of range");
    }

    Node* aux = this -> m_head -> next;

    for(int i{0}; i < index; i++){
        aux = aux -> next;
    }

    return aux -> value;
}