#ifndef BST_H
#define BST_H

#include<functional>
#include<ostream>
#include<initializer_list>

class BST
{
public:
    class Node;

    //Constructors and the destructor
    BST(std::initializer_list<int> node);// constructor
    BST()=default; // default constructor
    BST(const BST& bst); // copy constructor
    BST(BST&& bst); // move constructor
    ~BST(); // destructor

    // Methods
    friend std::ostream& operator<<(std::ostream& os,BST& bst);
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func)const;
    size_t length()const;
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

    // Operators
    const BST& operator++() const;
    const BST operator++(int) const;
    BST& operator=(const BST& bst); // BST operator = copy version
    BST& operator=(BST&& bst); // BST operator = move version

private:
    Node* root;
};  
class BST::Node
{
public:
    // Constructors:
    Node(int value, Node* left = nullptr, Node* right = nullptr); // Constructor
    Node() = default; // default constructor
    Node(const Node& node); // copy constructor

    // Operators:
    std::partial_ordering operator<=>(const int& _value) const { return value <=> _value; }
    bool operator==(const int& _value) const { return value == _value; }
    // Node& operator=(const Node& node); // Node operator = copy version
    // Node& operator=(Node&& node); // Node operator = move version
    friend std::ostream& operator<<(std::ostream& os, const BST::Node& node);
    
    int value;
    Node* left;
    Node* right;
};


#endif //BST_H