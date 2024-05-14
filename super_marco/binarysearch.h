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
    int price;
    node* right;
    node* left;
    node(){left = right = nullptr;}
    node(t& elt ,t& k,int p,node* l = 0 ,node* r = 0){
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
    void insert (t item,t kind ,int price);
    void print() ;
    void printInOrder(node<t>* currentNode) ;
    void printfl();
    void printInOrderfl(node<t>* currentNode) ;
};
#endif
