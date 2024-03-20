#include "../include/table.h"
#include <iostream>
#include <fstream>

using namespace std;

Table::Table(const string& tableName, const vector<string>& columnNames) 
    : name(tableName), columns(columnNames), filename(tableName + ".txt") {}

void Table::createTable() {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Failed to create table file\n";
        return;
    }
    
    for (const auto& col : columns) {
        file << col << "\t";
    }
    file << endl;
    file.close();
}

void Table::dropTable() {
    if (remove(filename.c_str()) != 0) {
        cerr << "Error: Failed to drop table\n";
    } else {
        cout << "Table " << name << " dropped successfully\n";
    }
}

void Table::insertRecord(const vector<string>& values) {
    if (values.size() != columns.size()) {
        cerr << "Error: Number of values does not match number of columns\n";
        return;
    }
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Failed to open table file for writing\n";
        return;
    }
    for (const auto& value : values) {
        file << value << "\t";
    }
    file << endl;
    file.close();
}

bool Table::updateRecord(int index, const vector<string>& newValues) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error: Failed to open table file for update\n";
        return false;
    }
    string line;
    int currentIndex = 0;
    while (getline(inFile, line)) {
        if (currentIndex == index) {
            
            size_t startPos = 0;
            for (const auto& newValue : newValues) {
                size_t endPos = line.find('\t', startPos);
                outFile << newValue << "\t";
                startPos = endPos + 1;
            }
            outFile << endl;
        } else {
            outFile << line << endl;
        }
        currentIndex++;
    }
    inFile.close();
    outFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    return true;
}

bool Table::deleteRecord(int index) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error: Failed to open table file for delete\n";
        return false;
    }
    string line;
    int currentIndex = 0;
    while (getline(inFile, line)) {
        if (currentIndex != index) {
            outFile << line << endl;
        }
        currentIndex++;
    }
    inFile.close();
    outFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    return true;
}

void Table::printTable() const {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Failed to open table file for reading\n";
        return;
    }
    
    for (const auto& col : columns) {
        cout << col << "\t";
    }
    cout << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
