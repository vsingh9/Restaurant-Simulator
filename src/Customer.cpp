#include "../header/Customer.h"

#include <iostream>
#include <cstdlib>      
using namespace std;

Customer::Customer() {
    groupSize = 0;
}

Customer::Customer(int numPeople, vector<string>& names, int menuItemsNum) {
    groupSize = numPeople;
    numMenuItems = menuItemsNum;
    // copy names into customerNames
    for (int i = 0; i < names.size(); i++) {
        customerNames.push_back(names.at(i));
    }
}

OrderNode Customer::generateRandomOrder(string name) {
    int randomOrderNumber = rand() % numMenuItems + 1;      // random number from 1 to largest menuItem number
    OrderNode newOrder;
    newOrder.customerName = name;
    newOrder.itemNumber = randomOrderNumber;
    return newOrder;
    
}
 
void Customer::generateOrders(vector<OrderNode>& listOfOrders) {
    for (int i = 0; i < groupSize; i++) {
        string currentName = customerNames.at(i);
        OrderNode nextOrder = generateRandomOrder(currentName);
        listOfOrders.push_back(nextOrder);
    }
}

//TO-DO
int Customer::payBill() {
    return 0;
}

/* 
Generate a rating for the restaurant
Good = false -> rating is between 1.0 - 3.0
Good = true -> rating is between 3.0 - 5.0
*/
double Customer::generateRating(bool good) {
    double rating = 0;
    if (good) {
        rating = rand() % 30 + 1;           // random int from 1 - 30
    } else {
        rating = rand() % 21 + 30;      // random int from 30 - 50
    }
    rating = rating / 10;
    return rating;
}

const int Customer::getGroupSize() {
    return groupSize;
}

void Customer::setGroupSize(int value) {
    groupSize = value;
}