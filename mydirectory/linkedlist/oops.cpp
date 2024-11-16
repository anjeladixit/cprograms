#include <iostream>
using namespace std;

// Class to represent a Complex number
class Complex {
private:
    float real;   // Real part
    float imag;   // Imaginary part

public:
    // Constructor to initialize Complex number
    Complex();
    Complex(float r , float i ) : real(r), imag(i) {}

    // Method to add two Complex numbers
    void add(const Complex c1, const Complex c2) {
        this->real = c1.real + c2.real;  // Use this pointer to access the current object's real
        this->imag = c1.imag + c2.imag;  // Use this pointer to access the current object's imag
    }

    // Method to print the Complex number
    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Creating two complex numbers
    Complex c1(3.4, 5.6);
    Complex c2(1.2, 4.3);

    cout << "Complex Number 1: ";
    c1.print();

    cout << "Complex Number 2: ";
    c2.print();

    // Creating a Complex object to store the sum
    Complex sum;

    // Adding the two complex numbers using the add function
    sum.add(c1, c2);

    cout << "Sum of Complex Numbers: ";
    sum.print();

    return 0;
}
