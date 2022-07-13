#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H


#include <iostream>

using namespace std;

class Order {
    public:
        int id;
        string productName;
        double price;
        string customerName;
        string date;
        string status;
        // int quantity;

        //for initialization
        Order(){}

        //Constructor overloading
        Order(int id, string productName, double price, string customerName, string date, string status)
        {
            this->id = id;
            this->productName = productName;
            this->price = price;
            this->customerName = customerName;
            this->date = date;
            this->status = status;
        }

        void displayAll(){
            cout << id << " " << productName << " " << price << " " << customerName << " " << date << " " << status << " " << endl;
        }
};


#endif