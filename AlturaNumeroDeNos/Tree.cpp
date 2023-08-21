#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr){
        this -> key = k;
        this -> left = l;
        this -> right = r;
    }
};

Tree::Tree(std::string serial){
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

//leitura de dados e construção da arvore
void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#"){
        return
    }

    int key = std::stoi(value);
    *node = new Node(key);

    _serializeTree(ss, &((node) -> left));
    _serializeTree(ss, &((node) -> right));
}

//destrutor
Tree::~Tree() {
    _root = _clear(_root);
}

//clear em nós
Node *Tree::_clear(Node *node) {
    if(node != nullptr){
        node -> left = _clear(node -> left);
        node -> right = _clear(node -> right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr){
        _inorder(node -> left);
        std::cout << node -> key << " ";
        _inorder(node -> right);
    }
}

void Tree::bshow() {
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

int Tree::size() { //TODO
    return _size(_root);
}

int Tree::_size(Node *node) { // TODO
    if(node == nullptr){
        return 0;
    }

    return 1 + _size(node -> left) + _size(node => right);
}

int Tree::height() { // TODO
    return _height(_root);
}

int Tree::_height(Node *node) {
    if(node == nullptr){
        return 0;
    }
    if(node -> left != nullptr && node -> right != nullptr){
        int left = _height(node -> left);
        int right = _height(node -> right);

        if(left > right){
            return 1 + left;
        }else {
            return 1 + right;
        }
    }else if(node -> left == nullptr && node -> right != nullptr){
        return 1 + _height(node -> left);
    }else if(node -> left != nullptr && node -> right == nullptr){
        return 1 + _height(node -> right);
    }else{ 
        return 1;
    }
}
 