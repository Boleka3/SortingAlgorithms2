#include<bits/stdc++.h>
using namespace std;

class Product {
private:
    string itemName;
    string category;
    int price;
public:
    Product(string name, string category, int price) : itemName(name), category(category), price(price) {}

    string getName() const { return itemName; }
    
    string getCategory() const { return category; }
    
    int getPrice() const { return price; }
    bool operator<(const Product& other) {
        return itemName < other.itemName;
    }
    bool operator>(const Product& other) {
        return itemName > other.itemName;
    }

    bool operator==(const Product& other) {
        return itemName == other.itemName and category == other.category and price == other.price;
    }

    bool operator!=(const Product& other) {
        return itemName != other.itemName and category != other.category and price != other.price;
    }
    
    void print() {
        cout << "Product: " << itemName << ", Category: " << category << ", Price: " << price << endl;
    }

    friend ostream& operator<<(ostream& os, const Product& item) {
        os << "Product: " << item.itemName << ", Category: " << item.category << ", Price: " << item.price << endl;
        return os;
    }
};