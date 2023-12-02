#ifndef PHONE_BOOK_FUNCTIONS_H
#define PHONE_BOOK_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int GetNumberOfLinesInFile(string path) {
    int count = 0;

    string str;

    ifstream file;
    file.open(path);

    while (getline(file, str)) {
        ++count;
    }

    file.close();
    return count;
}

string* FillArrayLinesFromFile(string path, int *size) {
    *size = GetNumberOfLinesInFile(path);
    string *result = new string[*size];

    ifstream file;
    file.open(path);

    string str;
    int i = 0;

    while (getline(file, str)) {
        result[i++] = str;
    }

    file.close();
    return result;
}

string Parser(string* str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, position);
    *str = str->substr(position + 1);

    return result;
}


string ParserToInitials(string *str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, 1);
    *str = str->substr(position + 1);
    return result;
}

void WriteArrayToFile(string path, string *array, int size) {
    ofstream file;
    file.open(path, ios_base::trunc);

    for (int i = 0; i < size; ++i) {
        file << array[i] << endl;
    }

    file.close();
}

void PrintArray(string* array, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "]" << endl << endl;
}

string Parcer1(string &source, char &correct) {
    ifstream file;
    file.open(source);
    string temp;
    while (getline(file, temp)) {
        for (int i = 0; i < temp.length() - 1; ++i) {
            if (temp[i] >= 58 && temp[i] <= 64) {
                temp[i] = correct;
            }
        }
    }
    file.close();
    return temp;

}

void Write(string &source, string &str) {
    ofstream file;
    file.open(source);
    file << str;
    file.close();
}

string PasswordGenerator(int length, int small, int capitals, int numbers, int symbols, string &small_arr, string &capitals_arr, string &numbers_arr, string &symbols_arr){
    string result;
    int index = 0;
    string pass_arr[length];
    for (int i = 0; i < small; i++) {
        pass_arr[index] = small_arr[rand() % small];
        index++;
    }
    for (int j = 0; j < capitals; ++j) {
        pass_arr[index] = capitals_arr[rand() % capitals];
        index++;
    }
    for (int k = 0; k < numbers; ++k) {
        pass_arr[index] = numbers_arr[rand() % numbers];
        index++;
    }
    for (int l = 0; l < symbols; ++l) {
        pass_arr[index] = symbols_arr[rand() % symbols];
        index++;
    }
    for (int i = 0; i < length; i++){
        result += pass_arr[i];
    }
    return result;
}
#endif //PHONE_BOOK_FUNCTIONS_H
