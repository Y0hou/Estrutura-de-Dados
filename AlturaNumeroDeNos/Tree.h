#ifdef TREE_H
#define TREE_H
#include <string>
#include <sstream>

struct node;

class Tree{
private:
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _bshow(Node *node, std::string heranca);
    void _serializeTree(std::stringstream& ss, Node **node);
    int _size(Node *node);
    int _height(Node *node);
public:
    Tree(std::string serial);
    void inorder();
    void bshow(); //teste para printar arvore
    int size();
    int height();
    ~Tree();
};



#endif