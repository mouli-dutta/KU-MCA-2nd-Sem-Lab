#include <iostream>

class TIME {
private:
    int hour;
    int minute;
    int second;

public:
    // Default constructor
    TIME() : hour(0), minute(0), second(0) {}

    // Parameterized constructor
    TIME(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Member function to display time in HH:MM:SS format
    void displayTime() const {
        printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
    }

    // Operator overloading to add two TIME objects
    TIME operator+(const TIME& other) const {
        TIME sum;
        sum.hour = hour + other.hour;
        sum.minute = minute + other.minute;
        sum.second = second + other.second;

        if (sum.second >= 60) {
            sum.minute += sum.second / 60;
            sum.second %= 60;
        }

        if (sum.minute >= 60) {
            sum.hour += sum.minute / 60;
            sum.minute %= 60;
        }

        return sum;
    }
};

int main() {
    int h1, m1, s1, h2, m2, s2;

    std::cout << "Enter time 1 (hours minutes seconds): ";
    std::cin >> h1 >> m1 >> s1;

    std::cout << "Enter time 2 (hours minutes seconds): ";
    std::cin >> h2 >> m2 >> s2;

    TIME t1(h1, m1, s1);
    TIME t2(h2, m2, s2);

    std::cout << "Time 1: ";
    t1.displayTime();

    std::cout << "Time 2: ";
    t2.displayTime();

    TIME sum = t1 + t2;
    std::cout << "Sum of Time 1 and Time 2: ";
    sum.displayTime();

    return 0;
}

