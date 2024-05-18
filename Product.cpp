//
// Created by HP on 5/18/2024.
//
#include "Product.h"
#include<bits/stdc++.h>

Product::Product(string itemName, string category, int price) : itemName(itemName), category(category), price(price) {}
string Product:: getName() const { return itemName; }

string Product:: getCategory() const { return category; }

int Product:: getPrice() const { return price; }
bool Product:: operator<(const Product& other) {
    return itemName < other.itemName;
}
bool Product:: operator>(const Product& other) {
    return itemName > other.itemName;
}

bool Product:: operator==(const Product& other) {
    return itemName == other.itemName and category == other.category and price == other.price;
}

bool Product:: operator!=(const Product& other) {
    return itemName != other.itemName and category != other.category and price != other.price;
}

void Product:: print() {
    cout << "Product: " << itemName << ", Category: " << category << ", Price: " << price << endl;
}

ostream& operator<<(ostream& os, const Product& item) {
    os << "Product: " << item.itemName << ", Category: " << item.category << ", Price: " << item.price << endl;
    return os;
}
