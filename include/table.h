#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>

class Table {
private:
    std::string name;
    std::vector<std::string> columns;
    std::string filename;

public:
    Table(const std::string& tableName, const std::vector<std::string>& columnNames);
    void createTable();
    void dropTable();
    void insertRecord(const std::vector<std::string>& values);
    bool updateRecord(int index, const std::vector<std::string>& newValues);
    bool deleteRecord(int index);
    void printTable() const;
};

#endif // TABLE_H
