#include <iostream>
#include <algorithm>

class Pattern
{
private:
    std::string s;

    // returns the first line of the pattern
    // e.g. inp = ABC, return ABCBA
    std::string buildFirst(std::string inp) {
        return inp + strrev(inp).substr(1);
    }

    // reverses a string
    std::string strrev(std::string inp) {
        reverse(inp.begin(), inp.end());
        return inp;
    }

    // repeats space character for n number of times
    std::string repeat(int n) {
        if(n > 0) {
            std::string res;
            for(int i = 0; i < n; i++) res += " ";
            return res;
        } 
        else return "";
    }

public:
    void setChar(char ch) {
        std::string inp;
        for(char c = 'A'; c <= ch; c++) inp += c;
        s = buildFirst(inp);
    }

    void setLen(int len) {
        std::string inp;
        for(int i = 65; i < 65+len; i++) inp += (char)i;
        s = buildFirst(inp);
    }

    void print() {
        std::cout << "\n";
        int len = s.length()/2;
        for (int i = 0; i <= len; i++) {
            int start = len - i;
            int end = len + i;
            int diff = end-start+1;

            std::cout << s << "\n";
            s.replace(s.begin()+start, s.begin()+end+1, repeat(diff));
        }
        std::cout << "\n";
    }
};

int main() {
    Pattern p;

    std::cout << "\n\t\tMENU\n"
              << "1. Print pattern with char.\n"
              << "2. Print pattern with length.\n"
              << "3. Exit.\n";

    while(1) {
        std::cout << "Enter your choice between 1 to 3.\n";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter the character.\n";
                char charInp;
                std::cin >> charInp;

                p.setChar(toupper(charInp));
                p.print();
        
            break;

            case 2:
                std::cout << "Enter the length.\n";
                int len;
                std::cin >> len;

                p.setLen(len);
                p.print();

            break;

            case 3:
                std::cout << "Terminating the program\n";
                exit(0);
            break;

            default:
                std::cout << "Please enter a number between 1 to 3.\n";
            break;
        }
    }
}