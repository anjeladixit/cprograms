#include <iostream>
#include <cmath> // For using M_PI constant

using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area
    double area()  {
        return 0;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Override area function to calculate the area of the circle
    double area()  {
        return M_PI * radius * radius;  // Area formula for a circle: π * r^2
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor to initialize side length
    Square(double s) : side(s) {}

    // Override area function to calculate the area of the square
    double area()  {
        return side * side;  // Area formula for a square: side^2
    }
};

int main() {
    // Create a Circle object with radius 5
    Circle circle(5);
    
    // Create a Square object with side length 4
    Square square(4);

    // Display the area of the Circle and Square
    cout << "Area of the Circle with radius 5: " << circle.area() << endl;
    cout << "Area of the Square with side length 4: " << square.area() << endl;

    return 0;
}
