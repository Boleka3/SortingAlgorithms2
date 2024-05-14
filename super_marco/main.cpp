#include <iostream>
#include "binarysearch.cpp"
using namespace std;

//================================================================
void displayMenu() {
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
void clearScreen() {
    // ANSI escape code to clear the screen
    cout << "\033[2J\033[H";
}
//======================================================================
//======================================================================
void binary(){
    binarysearch<string> list;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                clearScreen();
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                list.insert(name,kind,price);
                clearScreen();
                break;
            }
            case 2: {
                clearScreen();
                string name;
                cout<<"\nput name item you want remove: ";
                cin.ignore();
                getline(cin,name);
                list.remove(name);
                clearScreen();
                break;
            }
            case 3: {
                clearScreen();
                //your function
                break;
            }
            case 4: {
                clearScreen();
                list.print();
                break;
            }
            case 5: {
                clearScreen();
                list.printfl();
                break;
            }
            case 6: {
                clearScreen();
                //your function
                break;
            }
            case 7: {
                clearScreen();
                //your function
                break;
            }
            case 0:
                clearScreen();
                cout << "closing menu" << endl;
                break;
            default:
                clearScreen();
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}
//======================================================================
void avl(){
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                clearScreen();
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                //your function
                clearScreen();
                break;
            }
            case 2: {
                clearScreen();
                string name;
                cout<<"\nput name item you want remove: ";
                cin.ignore();
                getline(cin,name);
                //your function
                clearScreen();
                break;
            }
            case 3: {
                clearScreen();
                //your function
                break;
            }
            case 4: {
                clearScreen();
                //your function
                break;
            }
            case 5: {
                clearScreen();
                //your function
                break;
            }
            case 6: {
                clearScreen();
                //your function
                break;
            }
            case 7: {
                clearScreen();
                //your function
                break;
            }
            case 0:
                clearScreen();
                cout << "closing menu" << endl;
                break;
            default:
                clearScreen();
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}
//======================================================================
void heap(){
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                clearScreen();
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                //your function
                clearScreen();
                break;
            }
            case 2: {
                clearScreen();
                string name;
                cout<<"\nput name item you want remove: ";
                cin.ignore();
                getline(cin,name);
                //your function
                clearScreen();
                break;
            }
            case 3: {
                clearScreen();
                //your function
                break;
            }
            case 4: {
                clearScreen();
                //your function
                break;
            }
            case 5: {
                clearScreen();
                //your function
                break;
            }
            case 6: {
                clearScreen();
                //your function
                break;
            }
            case 7: {
                clearScreen();
                //your function
                break;
            }
            case 0:
                clearScreen();
                cout << "closing menu" << endl;
                break;
            default:
                clearScreen();
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}

int main() {
    cout<<"welcom to super marco\nchose type sort"<<endl;
    int sort;
    cout << "1. binary" << endl;
    cout << "2. avl" << endl;
    cout << "3. heap" << endl;
    cin>>sort;
    clearScreen();
    if (sort == 1){
        binary();
    }
    else if (sort == 2){
        avl();
    }
    else {
        heap();
    }
}
