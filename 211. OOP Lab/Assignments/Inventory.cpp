#include <iostream>
#include <fstream>

using namespace std;

struct Inventory {
    char itemName[50];
    int itemId;
    int totalItem;
    double itemCost;
    double totalCost;
};

int main() {

    Inventory items[] = {
        {"Item 1", 1, 10, 5.99, 50.0},
        {"Item 2", 2, 5, 9.99, 90.0},
        {"Item 3", 3, 2, 14.99, 127.0}
    };

    ofstream invFile("Inventory.txt", ios::binary);

    for(auto &item : items) {
        invFile << "Item Name: " << item.itemName << "\n"
                << "Item ID: " << item.itemId << "\n"
                << "Total no. of items: " << item.totalItem << "\n"
                << "Item cost: " << item.itemCost << "\n"
                << "Total cost: " << item.totalCost << "\n";
    }

    invFile.close();

    ifstream inpFile("Inventory.txt");
    ofstream copyFile("InventoryCopy.txt");

    string line;
    if(inpFile && copyFile) {
        while(getline(inpFile, line)) {
            copyFile << line << "\n";
        }
        cout << "Copy finished\n";
    }

    inpFile.close();
    copyFile.close();


    return 0;
}
