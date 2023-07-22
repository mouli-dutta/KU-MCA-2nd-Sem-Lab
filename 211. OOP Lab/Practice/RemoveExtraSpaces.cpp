#include <iostream>

using namespace std;

class MyString {
private:
    string str;

public:
    MyString(string str) {
        this->str = str;
    }

    string modify();
};

string MyString::modify()
{   
    int len = str.length();
    string res = "";

    for(int i = 0; i < len; i++) {
        if(!(str[i]== ' ' && str[i+1]== ' ')) {
            res += str[i];
        }
    }

    return res;
}

int main() {
    string str;
    getline(cin, str);
    MyString s(str);
    cout << s.modify() << "\n";
    return 0;
}
