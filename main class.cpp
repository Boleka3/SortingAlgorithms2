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
    Item(string name, string cat, int p) : itemName(name), category(cat), price(p) {}

    string getName() const { return itemName; }
    string getCategory() const { return category; }
    int getPrice() const { return price; }
};
