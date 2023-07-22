#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

class TextFileProcessor {
private:
    string inputFileName;
    string outputFileName;

public:
    TextFileProcessor(const string& inputFileName, const string& outputFileName)
        : inputFileName(inputFileName), outputFileName(outputFileName) {}

    void processFile() {
        ifstream inputFile(inputFileName);
        ofstream outputFile(outputFileName);

        if (!inputFile) {
            cout << "Error opening input file." << endl;
            return;
        }

        if (!outputFile) {
            cout << "Error creating output file." << endl;
            return;
        }

        char prevChar = '\0';
        char currentChar;
        bool isFirstLetter = true;

        while (inputFile.get(currentChar)) {
            if (isspace(currentChar)) {
                if (prevChar != ' ') {
                    outputFile << ' ';
                }
            } else {
                if (isFirstLetter) {
                    outputFile << static_cast<char>(toupper(currentChar));
                    isFirstLetter = false;
                } else {
                    outputFile << currentChar;
                }
            }

            prevChar = currentChar;

            if (currentChar == '\n') {
                isFirstLetter = true;
            }
        }

        inputFile.close();
        outputFile.close();

        cout << "File processing complete." << endl;
    }
};

int main() {
    string inputFileName, outputFileName;

    cout << "Enter input file name: ";
    cin >> inputFileName;

    cout << "Enter output file name: ";
    cin >> outputFileName;

    TextFileProcessor processor(inputFileName, outputFileName);
    processor.processFile();

    return 0;
}
