#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Item {
private:
    string itemName;
    string category;
    int price;

public:
    Item(string name, string cat, int pri) : itemName(name), category(cat), price(pri) {}

    string getItemName() const { return itemName; }
    string getCategory() const { return category; }
    int getPrice() const { return price; }

    void print() const {
        cout << "Item: " << itemName << ", Category: " << category << ", Price: " << price << endl;
    }

    bool operator<(const Item& other) const {
        return itemName < other.itemName;
    }
};
