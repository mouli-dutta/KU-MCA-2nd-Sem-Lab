#include<iostream>
#include<cmath>

using namespace std;

class Area
{

public:

    // area of circle
    double area(double r) {
        return 22/7.0 * r * r;
    }

    // area of rectangle
    double area(double A, double B) {
        return A * B;
    }

     // area of triangle: sq_root(s(s-a)(s-b)(s-c))
    double area(double A, double B, double C) {
        double s = (A + B + C) / 2;
        double a = s * (s-A) * (s-B) * (s-C);
        return sqrt(a);
    }
    
};

int main() {
    Area a;

    double radius;
    cout << "Enter the radius of the circle\n";
    cin >> radius;
    cout << "Area of the circle is: " << a.area(radius) << "\n\n";

    double len, wid;
    cout << "Enter the length and the width of the rectangle\n";
    cin >> len >> wid;
    cout << "Area of the rectangle is: " << a.area(len, wid) << "\n\n";

    double A, B, C;
    cout << "Enter the sides of the triangle\n";
    cin >> A >> B >> C;
    cout << "Area of the triangle is: " << a.area(A, B, C) << "\n\n";

    return 0;
}
