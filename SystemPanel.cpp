//
// Created by 29844 on 6/23/2023.
//

#include "SystemPanel.h"

#define USERNAME "user"
#define PASSWORD "123456"
using namespace std;

void SystemPanel::runPanel() {

    string username, password;
    cout << "System Panel" << endl;
    cout << "Please enter your username:";
    cin >> username;
    cout << "Please enter your password:";
    cin >> password;

    if (username == USERNAME && password == PASSWORD) {
        int choice;
        while (true) {
            cout << endl;
            cout << "Main Menu" << endl;
            cout << "1. Admin Login" << endl;
            cout << "2. Customer Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice:";
            cin >> choice;

            switch (choice) {
                case 1: {
                    AdminPanel adminPanel;
                    adminPanel.runPanel();
                    break;
                }
                case 2: {
                    CustomerPanel customerPanel;
                    customerPanel.runPanel();
                    break;
                }
                case 3:
                    cout << "Exiting the system..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } else {
        cout << "Invalid username or password." << endl;
    }
}

SystemPanel::~SystemPanel() {
}

SystemPanel::SystemPanel() {}
