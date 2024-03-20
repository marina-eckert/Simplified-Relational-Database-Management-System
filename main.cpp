#include <iostream>
#include "include/table.h"

int main() {
    std::vector<std::string> columns = {"ID", "Name", "Age"};

    Table table("Employees", columns);

    table.createTable();

    table.insertRecord({"1", "John", "30"});
    table.insertRecord({"2", "Alice", "25"});
    table.insertRecord({"3", "Bob", "35"});

    std::cout << "Table after insertion:\n";
    table.printTable();

    std::cout << "\nUpdating record at index 1:\n";
    table.updateRecord(1, {"2", "Alice", "26"});
    table.printTable();

    std::cout << "\nDeleting record at index 0:\n";
    table.deleteRecord(0);
    table.printTable();

    table.dropTable();

    return 0;
}
