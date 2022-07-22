#ifndef PO_H_
#define PO_H_

#include <iostream>
#include "order-class.h"

using namespace std;



class Node{
    public:
    Order order;
    Node *next;

};

class OrderLinkedList {
    public:
        Node *head, *tail;
        int size;
        int results = 0;
        string sortMode;
        string modifyMode;
        
        OrderLinkedList() {
            cout << "--- Constructing the LinkedList object ---" << endl;
            size = 0;
            head = NULL;
        }

        void insertAtEnd(string productName, double price, string customerName, string date, string status)
        {
            Node * newNode = new Node;
            int id = 0;

            //Inserting into empty list
            if(tail == NULL){
                id = 1;
                head = tail = newNode;
            }else{
                id = tail->order.id + 1;
                tail->next = newNode;
                tail = newNode;
            }

            //Insert all data
            newNode->order = Order(id,productName,price,customerName,date,status);
            newNode->next = nullptr;
            size++;
        }

        void display()
        {
            if(size == 0){
                cout<<"List is empty!";
            }else{
                Node * curr = head;
                cout << "\n--- DISPLAY ORDER LIST = " << size << " elements ---" << endl;
                cout << "ID" << " || " << "Product Name" << " || " << "Price (RM)" << " || " << "Customer Name" << " || " << "Date" << " || " << "Status" << endl;
                while( curr != nullptr)
                {
                    cout << curr->order.id << " " << curr->order.productName << " " 
                        << curr->order.price << " " << curr->order.customerName << " " 
                        << curr->order.date << " " << curr->order.status << " " << endl;
                    curr = curr->next;
                }
            }
        }

        void displayBackwards(Node * curr)
        {
            if(size == 0){
                cout<< "List is empty!";

            }else{
                if(curr != NULL){
                    displayBackwards(curr->next);
                    cout << curr->order.id << " " << curr->order.productName << " " 
                    << curr->order.price << " " << curr->order.customerName << " " 
                    << curr->order.date << " " << curr->order.status << " " << endl;
                }
            }

        }

        int getSize()
        {
            return size;
        }
        
        void modifyOrder(int id, string name)
        {
            Node *curr = head;
            if (modifyMode == "productName")
            {
                while (curr != NULL)
                {
                    if (curr->order.id == id)
                    {
                        curr->order.productName = name;
                        cout << "Order Successfully Updated" << endl;
                        break;
                    }
                    curr = curr->next;
                }
            }
            else if (modifyMode == "customerName")
            {
                while (curr != NULL)
                {
                    if (curr->order.id == id)
                    {
                        curr->order.customerName = name;
                        cout << "Order Successfully Updated" << endl;
                        break;
                    }
                    curr = curr->next;
                }
            }
            else if (modifyMode == "date")
            {
                while (curr != NULL)
                {
                    if (curr->order.id == id)
                    {
                        curr->order.date = name;
                        cout << "Order Successfully Updated" << endl;
                        break;                    
                    }
                    curr = curr->next;
                }
            }
             else if (modifyMode == "status")
            {
                while (curr != NULL)
                {
                    if (curr->order.id == id)
                    {
                        curr->order.status = name;
                        cout << "Order Successfully Updated" << endl;
                        break;             
                    }
                    curr = curr->next;
                }
            }
            cout << "Order ID not found" << endl;
        }

        void modifyOrderPrice(int id, double price)
        {
            Node *curr = head;
            while (curr != NULL)
            {
                if (curr->order.id == id)
                {
                    curr->order.price = price;
                    cout << "Order Successfully Updated" << endl;
                    break;
                }
                curr = curr->next;
            }
            
        }

        void deleteOrder(int id)
        {
            Node *prev = NULL;
            Node *curr = head;
            while(curr != NULL)
            {
                if(curr->order.id == id)
                {
                    if(prev !=NULL)
                    {
                        prev->next = curr->next;
                    }else{
                        head = curr->next;
                    }
                    delete curr;
                    cout << "Deleted Successfully" << endl;
                    size--;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if(curr == NULL){
                cout << "ID Not Found!";
            }

        }
        void searchOrderById(int id){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.id == id){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        void searchOrderByCustomerName(string customerName){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.customerName == customerName){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        void searchOrderByProductName(string productName){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.productName == productName){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        void searchOrderByDate(string date){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.date == date){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        void searchOrderByPriceRange(double priceBottom, double priceTop){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.price >= priceBottom && curr->order.price <= priceTop){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        void searchOrderByStatus(string status){
            Node *curr = head;
            while(curr != NULL){
                if(curr->order.status == status){
                    curr->order.displayAll();
                    results++;
                }
                curr = curr->next;
            }
            cout << "Total results found: " << results;
        }

        Node *merge(Node *leftHead, Node *rightHead){
            //base case
            if(leftHead == NULL){
                return rightHead;
            }
            if(rightHead == NULL){
                return leftHead;
            }

            //for recursion
            Node *curr;
            if(sortMode == "price"){
                if(leftHead->order.price < rightHead->order.price){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }else if(sortMode == "status"){

                if(leftHead->order.status < rightHead->order.status){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }else if(sortMode == "date"){

                if(leftHead->order.date < rightHead->order.date){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }else if(sortMode == "customerName"){

                if(leftHead->order.customerName < rightHead->order.customerName){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }else if(sortMode == "productName"){

                if(leftHead->order.productName < rightHead->order.productName){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }else{ //else sort by id, which is default

                if(leftHead->order.id < rightHead->order.id){
                    curr = leftHead;
                    curr->next = merge(leftHead->next, rightHead);
                }else{
                    curr = rightHead;
                    curr->next = merge(leftHead, rightHead->next);
                }
                return curr;

            }

        }

        Node * midPoint(Node *sortHead){

            Node *slow = sortHead;
            Node *fast = sortHead->next;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node * mergeSort(Node *sortHead){
            //base case
            if(sortHead == NULL || sortHead->next == NULL){
                return sortHead;
            }

            //recursive case
            Node * mid = midPoint(sortHead);

            //Splitting the Linked list into two
            Node * leftHead = sortHead;
            Node * rightHead = mid->next;
            mid->next = NULL;

            //Recursive sort
            leftHead = mergeSort(leftHead);
            rightHead = mergeSort(rightHead);

            //Merge
            return merge(leftHead,rightHead);

        }

        void updateHead(){
            head = mergeSort(head);
        }


};
OrderLinkedList orderLinkedList;


// int main()
// {
//     loadData();
//     orderLinkedList.modifyMode = "date";
//     orderLinkedList.modifyOrder(1 ,"Monitorrrrrrrr");
//     orderLinkedList.display();
//     orderLinkedList.display();
//     orderLinkedList.updateHead();
//     orderLinkedList.displayBackwards(orderLinkedList.head);
    
//     cout<<endl;
//     orderLinkedList.sortMode = "Status";
//     orderLinkedList.updateHead();
//     orderLinkedList.display();

//     cout<<endl;
//     orderLinkedList.sortMode = "Date";
//     orderLinkedList.updateHead();
//     orderLinkedList.updateHead();
//     orderLinkedList.displayBackwards(orderLinkedList.head);
//     cout<<"hello";
//     orderLinkedList.display();

//     for(int i=1;i<=6;i++){
//         orderLinkedList.deleteOrder(i);
//     }
//     orderLinkedList.deleteOrder(10);
//     orderLinkedList.searchOrderByCustomerName("Jerry");
//     orderLinkedList.searchOrderByProductName("Lamp");
//     orderLinkedList.searchOrderByDate("12-06-2022");
//     orderLinkedList.searchOrderByPriceRange(2000,2500);

// }
#endif