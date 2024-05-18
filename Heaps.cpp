#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include"Product.h"
using namespace std;


class Heap {
private:
    vector<Product> heap;

    void heapify(int i, bool minHeap) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest_smallest = i;

        if (minHeap) {
            if (left < heap.size() && heap[left].getPrice() < heap[largest_smallest].getPrice())
                largest_smallest = left;
            if (right < heap.size() && heap[right].getPrice() < heap[largest_smallest].getPrice())
                largest_smallest = right;
        } else {
            if (left < heap.size() && heap[left].getPrice() > heap[largest_smallest].getPrice())
                largest_smallest = left;
            if (right < heap.size() && heap[right].getPrice() > heap[largest_smallest].getPrice())
                largest_smallest = right;
        }

        if (largest_smallest != i) {
            swap(heap[i], heap[largest_smallest]);
            heapify(largest_smallest, minHeap);
        }
    }

    void buildHeap(bool minHeap) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            heapify(i, minHeap);
    }

public:
    void addProduct(const Product& item, bool minHeap) {
        heap.push_back(item);
        int i = heap.size() - 1;
        while (i > 0 && ((minHeap && heap[(i - 1) / 2].getPrice() > heap[i].getPrice()) ||
                         (!minHeap && heap[(i - 1) / 2].getPrice() < heap[i].getPrice()))) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void removeProduct(bool minHeap) {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0, minHeap);
    }

    void display() const {
        for (const auto& item : heap) {
            cout << "Product: " << item.getName() << ", Category: " << item.getCategory() << ", Price: " << item.getPrice() << endl;
        }
    }

    void sortHeap(bool minHeap) {
        buildHeap(minHeap);
        vector<Product> sortedHeap;
        while (!heap.empty()) {
            sortedHeap.push_back(heap[0]);
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0, minHeap);
        }
        heap = sortedHeap;
    }
};

// int main() {
//     Heap minHeap, maxHeap;
//     int choice;
//     bool manualInput = false;
//     string filename;

//     cout << "Do you want to input items manually or from a text file? (1 for manual, 2 for text file): ";
//     cin >> choice;
//     if (choice == 2) {
//         manualInput = false;
//         cout << "Enter the filename: ";
//         cin >> filename;
//     } else {
//         manualInput = true;
//     }

//     if (!manualInput) {
//         ifstream inputFile(filename);
//         if (!inputFile) {
//             cerr << "Error opening file." << endl;
//             return 1;
//         }
//         string name, category;
//         int price;
//         while (inputFile >> name >> category >> price) {
//             Product newProduct(name, category, price);
//             minHeap.addProduct(newProduct, true);
//             maxHeap.addProduct(newProduct, false);
//         }
//     } else {
//         cout << "Enter items in the format: Name Category Price. Enter 'done' to finish." << endl;
//         string name, category;
//         int price;
//         while (true) {
//             cout << "Enter item: ";
//             cin >> name;
//             if (name == "done")
//                 break;
//             cin >> category >> price;
//             Product newProduct(name, category, price);
//             minHeap.addProduct(newProduct, true);
//             maxHeap.addProduct(newProduct, false);
//         }
//     }

//     while (true) {
//         cout << "\nChoose an option:" << endl;
//         cout << "1. Min Heap" << endl;
//         cout << "2. Max Heap" << endl;
//         cout << "3. Exit" << endl;
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 cout << "\nChoose an operation for Min Heap:" << endl;
//                 cout << "1. Add item data" << endl;
//                 cout << "2. Remove item data" << endl;
//                 cout << "3. Display the item data normally" << endl;
//                 cout << "4. Display all the items sorted by their name ascending" << endl;
//                 cout << "5. Display all the items sorted by their name descending" << endl;
//                 cout << "6. Display all the items sorted by their prices ascending" << endl;
//                 cout << "7. Display all the items sorted by their prices descending" << endl;
//                 cin >> choice;

//                 switch (choice) {
//                     case 1: {
//                         cout << "Enter item details (Name Category Price): ";
//                         string name, category;
//                         int price;
//                         cin >> name >> category >> price;
//                         Product newProduct(name, category, price);
//                         minHeap.addProduct(newProduct, true);
//                         break;
//                     }
//                     case 2:
//                         minHeap.removeProduct(true);
//                         break;
//                     case 3:
//                         minHeap.display();
//                         break;
//                     case 4:
//                         minHeap.sortHeap(true);
//                         minHeap.display();
//                         break;
//                     case 5:
//                         minHeap.sortHeap(false);
//                         minHeap.display();
//                         break;
//                     case 6:
//                         minHeap.sortHeap(true);
//                         minHeap.display();
//                         break;
//                     case 7:
//                         minHeap.sortHeap(false);
//                         minHeap.display();
//                         break;
//                     default:
//                         cout << "Invalid option." << endl;
//                 }
//                 break;
//             }
//             case 2: {
//                 cout << "\nChoose an operation for Max Heap:" << endl;
//                 cout << "1. Add item data" << endl;
//                 cout << "2. Remove item data" << endl;
//                 cout << "3. Display the item data normally" << endl;
//                 cout << "4. Display all the items sorted by their name ascending" << endl;
//                 cout << "5. Display all the items sorted by their name descending" << endl;
//                 cout << "6. Display all the items sorted by their prices ascending" << endl;
//                 cout << "7. Display all the items sorted by their prices descending" << endl;
//                 cin >> choice;

//                 switch (choice) {
//                     case 1: {
//                         cout << "Enter item details (Name Category Price): ";
//                         string name, category;
//                         int price;
//                         cin >> name >> category >> price;
//                         Product newProduct(name, category, price);
//                         maxHeap.addProduct(newProduct, false);
//                         break;
//                     }
//                     case 2:
//                         maxHeap.removeProduct(false);
//                         break;
//                     case 3:
//                         maxHeap.display();
//                         break;
//                     case 4:
//                         maxHeap.sortHeap(true);
//                         maxHeap.display();
//                         break;
//                     case 5:
//                         maxHeap.sortHeap(false);
//                         maxHeap.display();
//                         break;
//                     case 6:
//                         maxHeap.sortHeap(true);
//                         maxHeap.display();
//                         break;
//                     case 7:
//                         maxHeap.sortHeap(false);
//                         maxHeap.display();
//                         break;
//                     default:
//                         cout << "Invalid option." << endl;
//                 }
//                 break;
//             }
//             case 3:
//                 return 0;
//             default:
//                 cout << "Invalid option." << endl;
//         }
//     }

//     return 0;
// }