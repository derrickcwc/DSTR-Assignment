#include <iostream>

#include "controller.h"
#include "login.h"

using namespace std;


void menu()
{
	cout << "\n ---Purchase Order Management System---" << endl;
	cout << "Please enter Username and Password to login." << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << endl;
}


void handleAction(int opt)
{
    switch (opt){
        case 1:
        {
            runUser();
            break;
        }
        case 2:
        {
            runAdmin();
            break;
        }
        case 0:
        {
            cout << "\n--------------------------------------------" << endl;
			cout << "> Thank You..." << endl;
			exit(0);
			break;
        }
    }
}


int main()
{
    menu();
    int opt = login(username, password);

    //Insert hardcoded data
    loadData();

    while(true){
        handleAction( opt );
    }


	cout << "\n--------------------------------------------" << endl;
	cout << "> Thank You..." << endl;

	return 0;
}