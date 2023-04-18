#include <iostream>

class Pattern
{
private:
    std::string s;

    // returns the first  line of the pattern given 'n'
    // e.g. n = 5 return ABCDEDCBA
    std::string buildFirst(int n) {
        std::string res;

        int A = 65;
        for(int i = -n; i < n-1; i++) {
            if(i < 0)
                res += (char) (A + n+i);
            else 
                res += (char) (A + n-i-2);
        }

        return res;
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
        int diff = (int) (ch - 'A') + 1;
        s = buildFirst(diff);
    }

    void setLen(int len) {
        s = buildFirst(len);
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