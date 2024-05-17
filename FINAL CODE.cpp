#include<bits/stdc++.h>
#include"Heaps.cpp"
#include"Product.cpp"
#include"AVL Trees.cpp"
#include"super_marco/binarysearch.h"
#include"super_marco/binarysearch.cpp"
using namespace std;

void bst();
void avl();
void heap();
void displayMenu();
void readFile(string filename);
void readTerminal();
void frstdisplayMenu();
vector<Product> ChronologicallySorted;

int main() {
    cout<<"Welcome to super marco\nchoose your data structure(:"<<endl;
    int sort;
    cout << "1. BST" << endl;
    cout << "2. AVL" << endl;
    cout << "3. Heap" << endl;
    cin>>sort;
    switch (sort)
    {
    case 1:
        bst();
        break;
    case 2: 
        avl();
        break;  
    case 3:
        heap();
        break;
    default:
        cout<<"invalid input\n";
        break;
    }
    int choice;
    bool manualInput = false;
    string filename;

    cout << "Do you want to input items manually or from a text file?\n1-for manual\n2 for text file:\n";
    cin >> choice;
    if (choice == 2) {
        cout << "Enter the filename: ";
        cin >> filename;
        readFile(filename);
    } else {
        manualInput = true;
    }

    if (!manualInput) {
    } else {
        cout << "Enter items in the format: Name Category Price. Enter 'done' to finish." << endl;
        string name, category;
        int price;
        while (true) {
            cout << "Enter item: ";
            getline(cin, name);
            cin >> category >> price;
            Product newProduct(name, category, price);
        }
    }

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Min Heap" << endl;
        cout << "2. Max Heap" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nChoose an operation for Min Heap:" << endl;
                cout << "1. Add item data" << endl;
                cout << "2. Remove item data" << endl;
                cout << "3. Display the item data normally" << endl;
                cout << "4. Display all the items sorted by their name ascending" << endl;
                cout << "5. Display all the items sorted by their name descending" << endl;
                cout << "6. Display all the items sorted by their prices ascending" << endl;
                cout << "7. Display all the items sorted by their prices descending" << endl;
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter item details (Name Category Price): ";
                        string name, category;
                        int price;
                        cin >> name >> category >> price;
                        Product newProduct(name, category, price);
                        minHeap.addProduct(newProduct, true);
                        break;
                    }
                    case 2:
                        minHeap.removeProduct(true);
                        break;
                    case 3:
                        minHeap.display();
                        break;
                    case 4:
                        minHeap.sortHeap(true);
                        minHeap.display();
                        break;
                    case 5:
                        minHeap.sortHeap(false);
                        minHeap.display();
                        break;
                    case 6:
                        minHeap.sortHeap(true);
                        minHeap.display();
                        break;
                    case 7:
                        minHeap.sortHeap(false);
                        minHeap.display();
                        break;
                    default:
                        cout << "Invalid option." << endl;
                }
                break;
            }
            case 2: {
                cout << "\nChoose an operation for Max Heap:" << endl;
                cout << "1. Add item data" << endl;
                cout << "2. Remove item data" << endl;
                cout << "3. Display the item data normally" << endl;
                cout << "4. Display all the items sorted by their name ascending" << endl;
                cout << "5. Display all the items sorted by their name descending" << endl;
                cout << "6. Display all the items sorted by their prices ascending" << endl;
                cout << "7. Display all the items sorted by their prices descending" << endl;
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter item details (Name Category Price): ";
                        string name, category;
                        int price;
                        cin >> name >> category >> price;
                        Product newProduct(name, category, price);
                        maxHeap.addProduct(newProduct, false);
                        break;
                    }
                    case 2:
                        maxHeap.removeProduct(false);
                        break;
                    case 3:
                        maxHeap.display();
                        break;
                    case 4:
                        maxHeap.sortHeap(true);
                        maxHeap.display();
                        break;
                    case 5:
                        maxHeap.sortHeap(false);
                        maxHeap.display();
                        break;
                    case 6:
                        maxHeap.sortHeap(true);
                        maxHeap.display();
                        break;
                    case 7:
                        maxHeap.sortHeap(false);
                        maxHeap.display();
                        break;
                    default:
                        cout << "Invalid option." << endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Invalid option." << endl;
        }
    }

    return 0;
}

void frstdisplayMenu() {
    int choice;
    bool manualInput = false;
    string filename;
    cout << "Do you want to input items manually or from a text file?\n1-for manual\n2-for text file:\n";
    cin >> choice;
    if (choice == 2) {
        cout << "Enter the filename: ";
        cin >> filename;
        readFile(filename);
    } else {
        manualInput = true;
    }
}

void readFile(string filename) {
    filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        while (getline(inputFile, name) && inputFile >> category >> price)
            ChronologicallySorted.push_back(Product(name, category, price));
}
void bst() {
    binarysearch list;
    binarysearch listp;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                Product item(name,kind,price);
                list.insert(item);
                listp.insert(item);
                break;
            }
            case 2: {
                string name, category;
                int price;
                cout<<"\nput name item you want remove: ";
                cin.ignore();
                getline(cin,name);
                cout<<"put price item you want remove: ";
                cin>>price;
                Product item(name, category, price);
                list.remove(item);
                break;
            }
            case 3: {
                //your function
                break;
            }
            case 4: {
                list.print();
                break;
            }
            case 5: {
                list.printfl();
                break;
            }
            case 6: {
                listp.print_pri();
                break;
            }
            case 7: {
                listp.printfl_pri();
                break;
            }
            case 0:
                cout << "closing menu" << endl;
                break;
            default:
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}