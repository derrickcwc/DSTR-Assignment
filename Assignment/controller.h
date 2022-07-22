#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "PO.h"

using namespace std;

string username, password;
string mode[] = {"productName", "price", "customerName", "date", "status"};
string status[] = {"Processing", "Released", "Received", "Canceled"};

void loadData()
{
    orderLinkedList.insertAtEnd("Monitor", 300.00, "Jimmy", "2022-10-07", "Received");
    orderLinkedList.insertAtEnd("Table", 150.00, "Jerry", "2022-10-08", "Received");
    orderLinkedList.insertAtEnd("Chair", 100.00, "Jerry", "2023-11-09", "Canceled");
    orderLinkedList.insertAtEnd("Computer", 1500.00, "Jony", "2022-10-10", "Processing");
    orderLinkedList.insertAtEnd("Lamp", 50.00, "Jason", "2022-09-23", "Processing");
    orderLinkedList.insertAtEnd("Laptop", 3000.00, "John", "2022-08-07", "Released");
    orderLinkedList.insertAtEnd("Computer", 1500.00, "Jony", "2022-12-31", "Processing");
    orderLinkedList.insertAtEnd("Lamp", 50.00, "Jason", "2022-03-01", "Processing");
    orderLinkedList.insertAtEnd("Laptop", 3000.00, "John", "2022-08-18", "Released");
    orderLinkedList.insertAtEnd("Pendrive", 65.00, "Jimmy", "2022-07-14", "Received");
    orderLinkedList.insertAtEnd("Pendrive", 65.00, "Rui Hong", "2022-07-14", "Canceled");
    orderLinkedList.insertAtEnd("Mouse", 130.00, "Jerry", "2020-11-09", "Canceled");
    orderLinkedList.insertAtEnd("Keyboard", 500.00, "Jony", "2018-10-11", "Processing");
    orderLinkedList.insertAtEnd("Wallet", 50.00, "Guang", "2022-08-19", "Received");
    orderLinkedList.insertAtEnd("Headphone", 290.00, "Nicholas", "2022-06-20", "Processing");
}

void runUser()
{
    cout << endl;
    cout << "---- Welcome " << username << "----" <<endl;

    //Display Order List
    orderLinkedList.display();
    cout << "\n--------------------------------------------" << endl;
    cout << endl;

    orderLinkedList.results = 0;
    int opt;
	cout << "1) Modify Order details" << endl;
	cout << "2) Search Order" << endl;
	cout << "3) Sort Order" << endl;
	cout << "4) Delete Order" << endl;

    cout << endl;
	cout << "0) Exit" << endl;

	cout << "> Choose: " << endl;
	cin >> opt;

    switch (opt){

        //Modify Order
        case 1:
        {
            cout << "Please insert the ID of the Order to be modified." << endl;

            cout << endl;
            cout << "0) Back" << endl;

            cout << "> Choose: " << endl;
            int id;
            cin >> id;

            if(id == 0) {
                runUser();
            }else{
                cout << "Please select what to modify." << endl;

                cout << endl;

                cout << "1) Product Name" << endl;
                cout << "2) Price" << endl;
                cout << "3) Customer Name" << endl;
                cout << "4) Date" << endl;
                cout << "5) Status" << endl;

                cout << endl;
                cout << "0) Back" << endl;

                cout << "> Choose: " << endl;
                cin >> opt;

                switch(opt){
                    case 1:
                    {
                        orderLinkedList.modifyMode = "productName";
                        cout << "Please insert new Product Name: " << endl;
                        string productName;
                        cin >> productName;

                        orderLinkedList.modifyOrder(id,productName);

                        break;
                    }
                    case 2:
                    {
                        orderLinkedList.modifyMode = "price";
                        cout << "Please insert new Price: " << endl;
                        double price;
                        cin >> price;

                        if(price > 0){
                            orderLinkedList.modifyOrderPrice(id,price);
                        }else{
                            cout << "Invalid Price!";
                        }

                        break;
                    }
                    case 3:
                    {
                        orderLinkedList.modifyMode = "customerName";
                        cout << "Please insert new customer Name:" << endl;
                        string customerName;
                        cin >> customerName;

                        orderLinkedList.modifyOrder(id,customerName);

                        break;
                    }
                    case 4:
                    {
                        orderLinkedList.modifyMode = "date";
                        cout << "Please insert new Date (format = YYYY-MM-DD):" << endl;
                        string date;
                        cin >> date;

                        orderLinkedList.modifyOrder(id, date);

                        break;
                    }
                    case 5:
                    {
                        orderLinkedList.modifyMode = "status";
                        cout << "Please select new Status:" << endl;

                        cout << endl;

                        cout << "1) Processing" << endl;
                        cout << "2) Released" << endl;
                        cout << "3) Received" << endl;
                        cout << "4) Canceled" << endl;

                        int choice;
                        cin >> choice;

                        orderLinkedList.modifyOrder(id, status[choice - 1]);

                        break;
                    }
                    case 0:
                    {
                        runUser();
                        break;
                    }
                    default:
                    {
                        cout << "\n--------------------------------------------" << endl;
                        cout << "> Thank You..." << endl;
                        exit(0);
                        break;
                    }
                }
            }
            break;
        }
        //Search Order
        case 2:
        {
            cout << "Please select what to search." << endl;

            cout << endl;

            cout << "1) ID" << endl;
            cout << "2) Product Name" << endl;
            cout << "3) Price" << endl;
            cout << "4) Customer Name" << endl;
            cout << "5) Date" << endl;
            cout << "6) Status" << endl;

            cout << endl;
            cout << "0) Back" << endl;

            cout << "> Choose: " << endl;
            cin >> opt;

            switch(opt){
                case 1:
                {
                    cout << "Please insert ID to search:" << endl;
                    int id;
                    cin >> id;

                    orderLinkedList.searchOrderById(id);

                    break;
                }
                case 2:
                {
                    cout << "Please insert Product Name to search:" << endl;
                    string productName;
                    cin >> productName;

                    orderLinkedList.searchOrderByProductName(productName);

                    break;
                }
                case 3:
                {
                    cout << "Please insert Price range to search : " << endl;
                    double priceBottom, priceTop;
                    cout << "Enter bottom Price range: ";
                    cin >> priceBottom;
                    cout << "Enter top Price range: ";
                    cin >> priceTop;

                    orderLinkedList.searchOrderByPriceRange(priceBottom,priceTop);

                    break;
                }
                case 4:
                {
                    cout << "Please insert Customer Name to search:" << endl;
                    string customerName;
                    cin >> customerName;

                    orderLinkedList.searchOrderByCustomerName(customerName);

                    break;
                }
                case 5:
                {
                    cout << "Please insert Date to search (ex: YYYY-MM-DD):" << endl;
                    string date;
                    cin >> date;

                    orderLinkedList.searchOrderByDate(date);
                    
                    break;
                }
                case 6:
                {
                    cout << "Please insert Status to search :" << endl;
                    string status;
                    cin >> status;
                    
                    orderLinkedList.searchOrderByStatus(status);
                    
                    break;
                }
                case 0:
                {
                    runUser();
                    break;
                }
                default:
                {
                    cout << "\n--------------------------------------------" << endl;
                    cout << "> Thank You..." << endl;
                    exit(0);
                    break;
                }
            }
            break;
        }
        //Sort Order
        case 3:
        {
            cout << "Please select what to sort." << endl;

            cout << endl;

            cout << "1) Product Name" << endl;
            cout << "2) Price" << endl;
            cout << "3) Customer Name" << endl;
            cout << "4) Date" << endl;
            cout << "5) Status" << endl;

            cout << endl;
            cout << "0) Back" << endl;

            cout << "> Choose: " << endl;
            cin >> opt;

            switch(opt){
                case 1:
                {
                    orderLinkedList.sortMode = mode[opt -1];
                    orderLinkedList.updateHead();
                    break;
                }
                case 2:
                {
                    orderLinkedList.sortMode = mode[opt -1];
                    orderLinkedList.updateHead();
                    break;
                }
                case 3:
                {
                    orderLinkedList.sortMode = mode[opt -1];
                    orderLinkedList.updateHead();
                    break;
                }
                case 4:
                {
                    orderLinkedList.sortMode = mode[opt -1];
                    orderLinkedList.updateHead();
                    break;
                }
                case 5:
                {
                    orderLinkedList.sortMode = mode[opt -1];
                    orderLinkedList.updateHead();
                    break;
                }
                case 0:
                {
                    runUser();
                    break;
                }
                default:
                {
                    cout << "\n--------------------------------------------" << endl;
                    cout << "> Thank You..." << endl;
                    exit(0);
                    break;
                }
            }

            break;
        }
        //Delete Order
        case 4:
        {
            cout << "Please insert the ID of the Order to be modified." << endl;

            cout << endl;
            cout << "0) Back" << endl;

            cout << "> Choose: " << endl;
            int id;
            cin >> id;
            orderLinkedList.deleteOrder(id);


            break;
        }
        //Exit
        case 0:
        {
            cout << "\n--------------------------------------------" << endl;
			cout << "> Thank You..." << endl;
			exit(0);
			break;
        }
        default:
        {
            cout << "\n--------------------------------------------" << endl;
			cout << "> Thank You..." << endl;
			exit(0);
			break;
        }
    }
}

void runAdmin()
{
    cout << endl;
    cout << "---- Welcome " << username << "----" <<endl;
}

#endif