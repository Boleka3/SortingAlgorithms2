
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
private:
    string itemName;
    string category;

public:
    int price;
    Item(string name, string category, int price) : itemName(name), category(category), price(price) {}

    bool operator<(const Item& other) {
        return itemName < other.itemName;
    }
    bool operator>(const Item& other) {
        return itemName > other.itemName;
    }


    void print() {
        cout << "Item: " << itemName << ", Category: " << category << ", Price: " << price << endl;
    }

    friend ostream& operator<<(ostream& os, const Item& item) {
        os << "Item: " << item.itemName << ", Category: " << item.category << ", Price: " << item.price << endl;
        return os;
    }
};

class AVLNode {
public:
    Item item;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Item item) : item(item), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, Item item) {
        if (node == nullptr) return new AVLNode(item);

        if (item < node->item)
            node->left = insertNode(node->left, item);
        else
            node->right = insertNode(node->right, item);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && item < node->left->item)
            return rightRotate(node);
        if (balance < -1 && item > node->right->item)
            return leftRotate(node);
        if (balance > 1 && item > node->left->item) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && item < node->right->item) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    AVLNode* deleteNode(AVLNode* root, Item key) {
        if (root == nullptr) return root;

        if (key < root->item)
            root->left = deleteNode(root->left, key);
        else if (key > root->item)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->item = temp->item;
                root->right = deleteNode(root->right, temp->item);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrderTraversal(AVLNode* root) {
        if (root == nullptr) return;
        inOrderTraversal(root->left);
        cout << root->item;
        inOrderTraversal(root->right);
    }

    void displayByNameAscending(AVLNode* root) {
        if (root == nullptr) return;
        displayByNameAscending(root->left);
        cout << root->item;
        displayByNameAscending(root->right);
    }

    // Function to display items sorted by name descending
    void displayByNameDescending(AVLNode* root) {
        if (root == nullptr) return;
        displayByNameDescending(root->right);
        cout << root->item;
        displayByNameDescending(root->left);
    }

    // Function to display items sorted by price ascending
    void displayByPriceAscending(AVLNode* root) {
        if (root == nullptr) return;

        vector<AVLNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            AVLNode* node = queue.front();
            queue.erase(queue.begin());

            cout << node->item;

            if (node->left != nullptr) queue.push_back(node->left);
            if (node->right != nullptr) queue.push_back(node->right);
        }

        vector<Item> items;
        for (const auto& node : queue) {
            items.push_back(node->item);
        }

        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price < b.price;
        });

        for (const auto& item : items) {
            cout << item;
        }
    }

    void displayByPriceDescending(AVLNode* root) {
        if (root == nullptr) return;

        vector<AVLNode*> queue;
        vector<Item> items;

        queue.push_back(root);

        while (!queue.empty()) {
            AVLNode* node = queue.front();
            queue.erase(queue.begin());

            items.push_back(node->item);

            if (node->left != nullptr) queue.push_back(node->left);
            if (node->right != nullptr) queue.push_back(node->right);
        }

        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price > b.price;
        });

        for (const auto& item : items) {
            cout << item;
        }
    }
public:
    AVLTree() : root(nullptr) {}

    void addItem(Item item) {
        root = insertNode(root, item);
    }

    void removeItem(Item item) {
        root = deleteNode(root, item);
    }

    void displayNormal() {
        inOrderTraversal(root);
    }

    // Function to display items sorted by name ascending


    void displayByNameAscending() {
        displayByNameAscending(root);
    }

    // Function to display items sorted by name descending
    void displayByNameDescending() {
        displayByNameDescending(root);
    }
    // Function to display items sorted by price ascending
    void displayByPriceAscending() {
        displayByPriceAscending(root);
    }

    // Function to display items sorted by price descending
    void displayByPriceDescending() {
        displayByPriceDescending(root);
    }
};

int main() {
    AVLTree tree;

    // Add some items
    tree.addItem(Item("Apple", "Fruit", 2));
    tree.addItem(Item("Carrot", "Vegetable", 3));
    tree.addItem(Item("Banana", "Fruit", 1));
    tree.addItem(Item("Milk", "Dairy", 4));

    cout << "Items Normal:" << endl;
    tree.displayNormal();

    cout << "Items sorted by name ascending:" << endl;
    tree.displayByNameAscending();

    cout << "\nItems sorted by name descending:" << endl;
    tree.displayByNameDescending();

    cout << "\nItems sorted by price ascending:" << endl;
    tree.displayByPriceAscending();

    cout << "\nItems sorted by price descending:" << endl;
    tree.displayByPriceDescending();

    Item ToRemove("Apple", "Fruit", 2);
    tree.removeItem(ToRemove);

    cout << "Items Normal:" << endl;
    tree.displayNormal();


    return 0;

}
