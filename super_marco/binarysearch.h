#ifndef SUPER_MARCO_BINARYSEARCH_H
#define SUPER_MARCO_BINARYSEARCH_H
#include <iostream>
#include <string>

using namespace std;
template <class t>
class node{
public:
    t data;
    t kind;
    t price;
    node* right;
    node* left;
    node(){left = right = nullptr;}
    node(t& elt ,t& k,t p,node* l = 0 ,node* r = 0){
        data = elt;
        kind = k;
        price = p;
        right = r;
        left = l;
    }
};
template <class t>
class binarysearch{
public:
    node<t>* root;
    binarysearch();
    bool isEmpty();
    bool search(t item) ;
    void remove(t item) ;
    void insert (t item,t kind ,t price);
    void print() ;
    void printInOrder(node<t>* currentNode) ;
    void printfl();
    void printInOrderfl(node<t>* currentNode) ;
    void print_pri() ;
    void printInOrder_pri(node<t>* currentNode) ;
    void printfl_pri();
    void printInOrderfl_pri(node<t>* currentNode) ;
};
#endif
