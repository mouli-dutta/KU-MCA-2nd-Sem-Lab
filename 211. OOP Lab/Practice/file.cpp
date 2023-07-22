#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(string filename) {
    fstream file;
    file.open(filename, ios::in);

    if (file.is_open())
    {
        string line;
        int count = 0;
        while(getline(file, line)) {
            cout << line;

            for(int i = 0; i < line.size(); i++) {
                if(line[i] == ' ')
                    count++;
            }
            count++;
        }

        cout << "\nTotal words = " << count << endl;

        file.close();
    }

}

int main() {

    readFile("dict.txt");
    return 0;
}