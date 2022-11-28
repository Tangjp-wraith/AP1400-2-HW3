#include "bst.h"
#include<queue>
#include<vector>
#include<iostream>
#include<stack>

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

std::ostream& operator<<(std::ostream& os,BST& bst){
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

BST::Node** BST::find_node(int _value){
    BST::Node* node_ptr{root};
    while(true){
        if(_value==node_ptr->value){
            break;
        }else if(_value<node_ptr->value){
            if(node_ptr->left==nullptr){
                return nullptr;
            }
            node_ptr=node_ptr->left;
        }else{
            if(node_ptr->right==nullptr){
                return nullptr;
            }
            node_ptr=node_ptr->right;
        }
    }
    BST::Node** node{new BST::Node*(node_ptr)};
    return node;
}

BST::Node** BST::find_parrent(int _value){
    BST::Node* node_ptr1{root};
    BST::Node* node_ptr2{root};
    while(true){
        if(_value==node_ptr1->value){
            break;
        }else if(_value<node_ptr1->value){
            if(node_ptr1->left==nullptr){
                return nullptr;
            }
            node_ptr2=node_ptr1;
            node_ptr1=node_ptr1->left;
        }else{
            if(node_ptr1->right==nullptr){
                return nullptr;
            }
            node_ptr2=node_ptr1;
            node_ptr1=node_ptr1->right;
        }
    }
    BST::Node** node{new BST::Node*(node_ptr2)};
    return node;
}

std::vector<BST::Node*> _Inorder_(BST::Node* root,std::vector<BST::Node*> vec){
    std::stack<BST::Node*> st;
    BST::Node* node_ptr{root};
    while(node_ptr!=nullptr||!st.empty()){
        while(node_ptr!=nullptr){
            st.push(node_ptr);
            node_ptr=node_ptr->left;
        }
        if(!st.empty()){
            node_ptr=st.top();
            vec.push_back(node_ptr);
            st.pop();
            node_ptr=node_ptr->right;
        }
    }
    return vec;
}

BST::Node** BST::find_successor(int _value){
    std::vector<BST::Node*> vec;
    vec=_Inorder_(root,vec);
    // for(auto& v:vec){std::cout<<*v<<std::endl;}
    for(int i=0;i<vec.size();i++){
        if(vec[i]->value==_value){
            BST::Node** node{new BST::Node*(vec[i+1])};
            return node;
        }
    }
    return nullptr;
}   

bool BST::delete_node(int _value){

}

const BST& BST::operator++() const{

}

const BST BST::operator++(int) const{
    BST _bst{*this};
    ++*this;
    return _bst;
}

BST& BST::operator=(const BST& bst){
    
}

BST& BST::operator=(BST&& bst){
    root=bst.root;
    bst.root=nullptr;
    return *this;
}