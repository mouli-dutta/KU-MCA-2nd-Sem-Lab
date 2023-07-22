#include <iostream>
#include <fstream>

using namespace std;

const int size = 100;

int main() {
    char countryArr[size], capitalArr[size];

    ofstream countryFile("Country.txt", ios::app);
    ofstream capitalFile("Capital.txt", ios::app);

    while(1) {
        cout << "Enter 1 to take input and 0 to stop\n";
        int choice;
        cin >> choice;

        if(choice == 0) break;

        cin.ignore();

        cout << "Enter the country name\n";
        cin.getline(countryArr, size);
        countryFile << countryArr << "\n";

        cout << "Enter the capital name\n";
        cin.getline(capitalArr, size);
        capitalFile << capitalArr << "\n";
    }

    countryFile.close();
    capitalFile.close();

    ifstream countryIn("Country.txt");
    ifstream capitalIn("Capital.txt");

    while(!countryIn.eof() && !capitalIn.eof()) {
        countryIn.getline(countryArr, size);
        capitalIn.getline(capitalArr, size);

        cout << "The capital of " << countryArr << " is " << capitalArr << "\n";
    }

    
    countryIn.close();
    capitalIn.close();
    

    return 0;
}