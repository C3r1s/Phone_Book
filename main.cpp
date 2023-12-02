#include <iostream>
#include <string>
#include <map>
#include "Map_Functions.h"
using namespace std;

int main() {
    map<string, string> database;
    int choice;
    string input_path = "D:\\Programming\\Phone_Book\\data.txt";
    char delimiter = '|';
    database = FromFileToMap(database, input_path, delimiter);
    cout << "WELCOME TO THE PHONE BOOK DATABASE" << endl;
    cout << "OPTIONS" << endl;
    cout << "1. Find contact" << endl;
    cout << "2. Add contact" << endl;
    cout << "3. Show all contacts" << endl;
    cout << "Please select an option:  "; cin >> choice;
    string search_number;
    string family_name;
    string name;
    string number;
    vector<string> vec;
    bool result;

    switch (choice){
        case 1:
            cout << "Enter the number:  "; cin >> search_number;
            result = FindContact(vec, database, search_number);
            CheckResult(result, search_number, vec);
            break;
        case 2:
            cout << "Required data: Family name, Name, Number" << endl;
            cout << "Enter the family name:  "; cin >> family_name;
            cout << "Enter the name:  "; cin >> name;
            cout << "Enter the number: "; cin >> number;
            AddContact(input_path, family_name, name, number);
            break;
        case 3:
            Print(database);
            break;
        default:
            cout << "!Incorrect Input!" << endl;
            break;
    }
}