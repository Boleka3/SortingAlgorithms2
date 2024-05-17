#ifndef SUPER_MARCO_BINARYSEARCH_H
#define SUPER_MARCO_BINARYSEARCH_H
#include <iostream>
#include <string>
#include"../Product.cpp"

using namespace std;
class node{
public:
    Product item;
    node* right;
    node* left;
    // node() : left(nullptr), right(nullptr) {}
    node(Product itm) : item(itm), left(nullptr), right(nullptr){}
};

class binarysearch{
public:
    node* root;
    binarysearch();
    bool isEmpty();
    bool search(Product item) ;
    void remove(Product item) ;
    void insert (Product item);
    void print() ;
    void printInOrder(node* currentNode) ;
    void printfl();
    void printInOrderfl(node* currentNode) ;
    void print_pri() ;
    void printInOrder_pri(node* currentNode) ;
    void printfl_pri();
    void printInOrderfl_pri(node* currentNode) ;
};
#endif
