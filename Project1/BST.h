/*
	Park, David
	CS A200
	October 28, 2015
 
	Exercise 13 Final
 */

#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
using namespace std;
template<typename T> class Node;
template<typename T> class BST;

template<typename T>
class Node
{
    friend class BST<T>;
public:
    Node(){}
    ~Node(){}
private:
    T data;
    Node *rlink, *llink;
};

template<typename T>
class BST
{
public:
    
    BST();
    //Default constructor
    
    ~BST();
    //Destructor
    
    void destroyTree();
    //Deallocates the memory space occupied by the BST
    
    void inorderTraversal() const;
    //Prints nodes of the BT in the inorder sequence
    
    int totalNodes() const;
    //Determines the number of nodes in the BST
    
    // Declaration function insert
    // Your code here...
    void insert(const T& insertItem);
    
    // Declaration function treeHeight()
    // Your code here...
    int treeHeight() const;
    
private:
    Node<T> *root; //Pointer to the root
    
    void destroyTree(Node<T>* &p);
    //Destroy the BST to which p points
    
    // Declaration function inorderTraversal(Node*)
    // Your code here...
    void inorderTraversal(Node<T> * nextRoot) const;
    
    // Declaration function treeHeight(Node*)
    // Your code here...
    int treeHeight(Node<T> * nextRoot) const;
    
    // Declaration totalNodes(Node*)
    // Your code here... 
    int totalNodes(Node<T> * nextRoot) const;

};

#endif