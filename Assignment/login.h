#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>

using namespace std;

int login(string user, string password){
    if(user == "user" && password == "user123"){
        cout << "Login Successful as User";
        return 1;

    }else if(user == "admin" && password == "admin123"){
        cout << "Login Successful as Admin";
        return 2;

    }else{
        cout << "Invalid Username or Password";
        return 0;
    }
}




#endif