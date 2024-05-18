#include<bits/stdc++.h>
#include"Heaps.cpp"
#include"AVL Trees.cpp"
#include"Product.cpp"
#include"binarysearch.cpp"
using namespace std;

void bst();
void avl();
void heap();
void displayMenu();
void readFile(string filename);
void readTerminal();
bool frstdisplayMenu();

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
        cout<<"fuck yourself 1";
        break;
    case 2: 
        avl();
        cout<<"fuck yourself 2";
        break;  
    case 3:
        heap();
        cout<<"fuck yourself 3";
        break;
    default:
        cout<<"invalid input\n";
        break;
    }
    return 0;
}

bool frstdisplayMenu() {
    int choice;
    bool manualInput = false;
    string filename;
    cout << "Do you want to input items manually or from a text file?\n1-for manual\n2-for text file:\n";
    cin >> choice;
    return  choice == 2;
}
void displayMenu(){
    cout << "\nMenu:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Remove item" << endl;
    cout << "3. Display all items" << endl;
    cout << "4. Display items sorted by name ascending" << endl;
    cout << "5. Display items sorted by name descending" << endl;
    cout << "6. Display items sorted by price ascending" << endl;
    cout << "7. Display items sorted by price descending" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------------" << endl;
}

void heap() {
    bool valid = frstdisplayMenu();
    Heap minHeap, maxHeap;
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            minHeap.addProduct(item, true);
            maxHeap.addProduct(item, false);
        }
    }
    int choice;
    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Min Heap" << endl;
        cout << "2. Max Heap" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
         switch (choice) {
            case 1: {
                displayMenu();
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
                displayMenu();
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
                return ;
            default:
                cout << "Invalid option." << endl;
        }
    } while (choice != 0);
}

void avl() {
    bool valid = frstdisplayMenu();
    AVLTree Tree;
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            Tree.addProduct(item);
        }
    }
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
                Tree.addProduct(item);
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
                Tree.removeProduct(item);
                break;
            }
            case 3: {
                Tree.displayNormal();
                break;
            }
            case 4: {
                Tree.displayByNameAscending();
                break;
            }
            case 5: {
                Tree.displayByNameDescending();
                break;
            }
            case 6: {
                Tree.displayByPriceAscending();
                break;
            }
            case 7: {
                Tree.displayByPriceDescending();
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

void bst() {
    bool valid = frstdisplayMenu();
    binarysearch list;
    binarysearch listp;
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            list.insert(item);
            listp.insert_pri(item);
        }
        inputFile.close();
    }
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
                listp.insert_pri(item);
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
                listp.remove_pri(item);
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
