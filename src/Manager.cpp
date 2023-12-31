#include "../header/Manager.h"
#include "../header/Employee.h"

#include <iostream>

using namespace std;

//manager class implementation
Manager::Manager() {
    head = nullptr;
    tail = nullptr;
}

Manager::~Manager() {

}

//add an item to the menu
void Manager::menuAdd(MenuItem* newNode) {
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

//change the price of an item on the menu with the newly requested price (need to test)
void Manager::changeMenuPrice(int itemNumber, double newPrice) {
    MenuItem* curr = head;

    if (isEmpty()) {
        cout << "Menu is empty" << endl; //throw?
        return;
    }

    while (curr != nullptr) {
        if (curr->getMenuNumber() == itemNumber) {
            curr->setFoodPrice(newPrice);
        }

        curr = curr->next;
    }

    delete curr;
    curr = nullptr;
}

//get specific item's food type
string Manager::getItemType(int itemNumber) {
    MenuItem* curr = head;
    for (int i = 1; i < itemNumber; i++) {
        curr = curr->next;
    }
    return curr->getFoodType();
}

string Manager::getItemName(int itemNumber) {
    MenuItem* curr = head;
    for (int i = 1; i < itemNumber; i++) {
        curr = curr->next;
    }
    return curr->getFoodItem();
}

int Manager::getLastMenuNumber() {
    MenuItem* curr = head;

    if (isEmpty()) {
        cout << "Menu is empty" << endl; //throw?
        exit(1);
    }

    while (curr->next != nullptr) {
        curr = curr->next;
    }
    
    return curr->getMenuNumber();
    delete curr;
    curr = nullptr;
}

//print the full menu
void Manager::viewFullMenu() {
    MenuItem* curr = head;

    if (isEmpty()) {
        cout << "Menu is empty" << endl; //throw?
        return;
    }

    cout << "---RESTAURANT MENU---" << endl;

    while (curr != nullptr) {
        curr->printMenuItem();
        cout << endl;

        curr = curr->next;
    }

    delete curr;
    curr = nullptr;
}

void Manager::clearFullMenu() {
    while (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            MenuItem* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
    }
}

//check if menu is empty
bool Manager::isEmpty() {
    return ((head == nullptr) && (tail == nullptr));
}

//print manager name prompt
void Manager::printCharacterDetails() {
    string name;
    cout << "Enter your manager name: ";
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Manager " << name << "! 🎉" << endl;
}

//returns the price of a specific menu item (0 if the number is larger)
double Manager::getPriceOfChosenMenuItem(int menuNumber) {
    double price = 0;
    if (head == nullptr) {
        return price;
    }
    if (menuNumber < 1 || menuNumber > getLastMenuNumber()) {
        return price;
    }
    MenuItem* currNode = head;
    for (int i = 0; i < menuNumber - 1; i++) {
        currNode = currNode->next;
    }
    price = currNode->getFoodPrice();
    return price;

    delete currNode;
    currNode = nullptr;
}