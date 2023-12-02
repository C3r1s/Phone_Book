#ifndef PHONE_BOOK_MAP_FUNCTIONS_H
#define PHONE_BOOK_MAP_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "Functions.h"

using namespace std;


map<string, string>FromFileToMap( map<string, string> map, string input_path, char delimiter){
    ifstream input_file;
    input_file.open(input_path);
    string input_data;
    while (!input_file.eof()) {
        getline(input_file, input_data);
        auto person = Parser(&input_data, delimiter);
        auto number = input_data;
        map.insert(pair<string, string>(person, number));
        input_data.clear();
    }
    return  map;
}

void Print (map<string, string> map){
    for (auto item : map) {
        cout << item.first << " : " << item.second << endl;
    }
}

void FindContact(map<string, string> map, string search){
    string key = search;
    string person = map[key];
    cout << search << " -> " << person << endl;
}

void AddContact(string input_path, string family_name, string name, string number) {
    ofstream output_file;
    string fullname = family_name + " " + name;
    output_file.open(input_path, ios_base::app);
    output_file << fullname << "|" << number << endl;
    cout << "Contact added succesfully" << endl;
}
bool FindContact(vector<string> &vec, map<string, string> map, string search) {
    string key = search;
    bool result = false;
    auto it = map.begin();
    while(it != map.end()) {
        if(it -> second == key) {
            result = true;
            vec.push_back(it -> first);
        }
        it++;
    }
    return result;
}

void CheckResult(bool result, string search, vector<string> &vec){
    if(result) {
        cout<<"Phone number " << search << " corresponds to a person ";
        for(auto item : vec) {
            cout << item << endl;
        }
    } else {
        cout << "!ERROR! Phone number not found!" << endl;
    }
}



#endif //PHONE_BOOK_MAP_FUNCTIONS_H
