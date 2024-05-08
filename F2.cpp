#include <iostream>
#include <string>

#define MAX_EMPLOYEES 20

using namespace std;

struct Employee {
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};

Employee emp[MAX_EMPLOYEES];
int num = 0;

void showMenu();
void insert();
void deleteRecord();
void searchRecord();

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    cout << "------------------------- Employee Management System -------------------------\n\n";
    cout << "Available Options:\n\n";
    cout << "Insert New Entry    (1)\n";
    cout << "Delete Entry        (2)\n";
    cout << "Search a Record     (3)\n";
    cout << "Exit                (4)\n";

    int option;
    cin >> option;

    switch (option) {
        case 1:
            insert();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            return;
        default:
            cout << "Expected Options are 1 to 4";
            showMenu();
            break;
    }
}

void insert() {
    if (num < MAX_EMPLOYEES) {
        cout << "Enter the information of the Employee.\n";
        cout << "Name: ";
        cin >> emp[num].name;

        cout << "Employee ID: ";
        cin >> emp[num].code;

        cout << "Designation: ";
        cin >> emp[num].designation;

        cout << "Experience: ";
        cin >> emp[num].exp;

        cout << "Age: ";
        cin >> emp[num].age;

        num++;
    } else {
        cout << "Employee Size Full\n";
    }
    showMenu();
}

void deleteRecord() {
    cout << "Enter the Employee ID to Delete Record: ";
    int code;
    cin >> code;
    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            for (int j = i; j < num - 1; j++) {
                emp[j] = emp[j + 1];
            }
            num--;
            found = true;
            cout << "Record deleted successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Record with Employee ID " << code << " not found.\n";
    }
    showMenu();
}

void searchRecord() {
    cout << "Enter the Employee ID to Search Record: ";
    int code;
    cin >> code;
    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Experience: " << emp[i].exp << "\n";
            cout << "Age: " << emp[i].age << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record with Employee ID " << code << " not found.\n";
    }
    showMenu();
}

