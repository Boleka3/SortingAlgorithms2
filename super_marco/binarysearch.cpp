#include "binarysearch.h"
using namespace std;
template <typename t>
binarysearch<t>::binarysearch() {
    root = nullptr;
}
//=================================================
template <typename t>
bool binarysearch<t>::isEmpty() {
    return root == nullptr;
}
//=================================================
template <typename t>
void binarysearch<t>::insert(t item ,t kind ,t price) {
    node<t>* p = root, *prev = nullptr;
    while (p != nullptr){
        prev = p;
        if (p->data < item)
            p = p->right;
        else
            p = p->left;
    }
    if (root == nullptr)
        root = new node<t>(item,kind,price);
    else if (prev->data < item)
        prev->right = new node<t>(item,kind,price);
    else
        prev->left = new node<t>(item,kind,price);
}
//=================================================
template <typename t>
void binarysearch<t>::remove(t item) {
    if (root == nullptr)
        return;
    node<t>* currentNode = root;
    node<t>* parent = nullptr;
    if (search(item) == 0)
        return;
    while (currentNode != nullptr && currentNode->data != item) {
        parent = currentNode;
        if (item < currentNode->data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    // Case 1 dont have children
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete currentNode;
    }
        // Case 2 have one children
    else if (currentNode->left == nullptr || currentNode->right == nullptr) {
        node<t>* child = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;
        }
        delete currentNode;
    }
        // Case 3 have two children
    else {
        node<t>* successor = currentNode->right;
        parent = nullptr;
        // find minim
        while (successor->left != nullptr) {
            parent = successor;
            successor = successor->left;
        }

        // Copy minim data to the current node
        currentNode->data = successor->data;

        // Remove minim
        if (parent != nullptr)
            parent->left = successor->right;
        else
            currentNode->right = successor->right;

        delete successor;
    }
}
//=================================================
template <typename t>
void binarysearch<t>::print() {
    printInOrder(root);
}
//=================================================
template <typename t>
void binarysearch<t>::printInOrder(node<t> *currentNode) {
    if (currentNode != nullptr) {
        printInOrder(currentNode->left);
        cout <<"item : "<<currentNode->data<<" ,kind : "<<currentNode->kind<<" ,price : "<<currentNode->price<<endl;
        printInOrder(currentNode->right);
    }
}
//=================================================
template <typename t>
void binarysearch<t>::printfl() {
    printInOrderfl(root);
}
//=================================================
template <typename t>
void binarysearch<t>::printInOrderfl(node<t> *currentNode) {
    if (currentNode != nullptr) {
        printInOrderfl(currentNode->right);
        cout <<"item : "<<currentNode->data<<" ,kind : "<<currentNode->kind<<" ,price : "<<currentNode->price<<endl;
        printInOrderfl(currentNode->left);
    }
}
//=================================================
template <typename t>
void binarysearch<t>::print_pri() {
    printInOrder_pri(root);
}
//=================================================
template <typename t>
void binarysearch<t>::printInOrder_pri(node<t> *currentNode) {
    if (currentNode != nullptr) {
        printInOrder_pri(currentNode->left);
        cout <<"price : "<<currentNode->data<<" ,name : "<<currentNode->kind<<" ,kind : "<<currentNode->price<<endl;
        printInOrder_pri(currentNode->right);
    }
}
//=================================================
template <typename t>
void binarysearch<t>::printfl_pri() {
    printInOrderfl_pri(root);
}
//=================================================
template <typename t>
void binarysearch<t>::printInOrderfl_pri(node<t> *currentNode) {
    if (currentNode != nullptr) {
        printInOrderfl_pri(currentNode->right);
        cout <<"price : "<<currentNode->data<<" ,name : "<<currentNode->kind<<" ,kind : "<<currentNode->price<<endl;
        printInOrderfl_pri(currentNode->left);
    }
}
//=================================================
template <typename t>
bool binarysearch<t>::search(t item) {
    node<t> *p = root;
    while (p != nullptr) {
        if (item == p->data)
            return 1;
        else if (item < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return 0;
}