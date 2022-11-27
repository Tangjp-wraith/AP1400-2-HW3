#include "bst.h"

// BST::Node 

BST::Node::Node(int _value, Node* _left,Node* _right)
    :value{_value},left{_left},right{_right}{}

BST::Node::Node(const Node& node)
    :value{node.value},left{node.left},right{node.right}{}

std::ostream& operator<<(std::ostream& os, const BST::Node& node){
    os << &node << "\t=> value:" << node.value << "\t   ";
    os << "left:" << std::left;
    os.width(12);
    os << node.left << std::right;
    os.width(12);
    os << "right:" << std::left;
    os << node.right;
    return os;
}

//BST

BST::BST(std::initializer_list<int> node)
    :root{nullptr}
{
    for(const int* node_iterator_ptr=node.begin){
        this->add_node();
    }
}

BST::BST(const BST& bst)
    :root{nullptr}
{       

}   

BST::BST(BST&& bst)
    :root{}
{

}

BST::~BST(){
    std::vector<Node*> nodes;
    bfs([&nodes](BST::Node*& node){
        nodes.push_back(node);
        });
    for(auto& node:nodes){
        delete node;
    }
}

void BST::bfs(std::function<void(Node*& node)> func)const{

}   

BST::Node*& BST::get_root(){
    return root;
}

size_t BST::length() const{
    size_t len=0;
    this->bfs([&len](BST::Node*& node){
        len++;
    });
    return len;
}

bool BST::add_node(int value){

}