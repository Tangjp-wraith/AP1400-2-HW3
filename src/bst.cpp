#include "bst.h"
#include<queue>

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
    for(const int* node_iterator_ptr=node.begin();node_iterator_ptr!=node.end();node_iterator_ptr++){
        this->add_node(*node_iterator_ptr);
    }
}

BST::BST(const BST& bst)
    :root{nullptr}
{
    std::queue<BST::Node*> que;
    bst.bfs([&que](BST::Node*& node){
        que.push(node);
    });
    while(!que.empty()){
        this->add_node(que.front()->value);
        que.pop();
    }
}   

BST::BST(BST&& bst)
    :root{bst.get_root()}
{   
    bst.root=nullptr;
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
    if(root==nullptr){
        return;
    }
    std::queue<BST::Node*> que;
    que.push(root);
    while(!que.empty()){
        if(que.front()->left!=nullptr){
            que.push(que.front()->left);
        }
        if(que.front()->right!=nullptr){
            que.push(que.front()->right);
        }
        func(que.front());
        que.pop();
    }
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

bool BST::add_node(int _value){
    BST::Node* node=new BST::Node(_value);
    std::queue<BST::Node*> tree;
    if(root==nullptr){
        root=node;
        return true;
    }
    tree.push(root);
    while(!tree.empty()){
        if(_value==tree.front()->value){
            return false;
        }else if(_value<tree.front()->value){
            if(tree.front()->left==nullptr){
                tree.front()->left=node;
                return true;
            }else{
                if(_value==tree.front()->left->value){
                    return false;
                }
            }
            tree.push(tree.front()->left);
        }else{
            if(tree.front()->right==nullptr){
                tree.front()->right=node;
                return true;
            }else{
                if(_value==tree.front()->right->value){
                    return false;
                }
            }
            tree.push(tree.front()->right);
        }
        tree.pop();
    }
    return false;
}

std::ostream& operator<<(std::ostream& os,const BST& bst){
    os << std::string(80, '*') << std::endl;
    std::queue<BST::Node*> nodes;
    bst.bfs([&nodes](BST::Node*& node) {
         nodes.push(node); 
    });
    while (!nodes.empty()) {
        os << *nodes.front() << std::endl;
        nodes.pop();
    }
    os << "Binary Search tree size: " << bst.length() << std::endl;
    os << std::string(80, '*') << std::endl;
    return os;
}

BST::Node** find_node(int _value){

}