#include <iostream>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "I can eat!" << std::endl;
    }
    
    void sleep() {
        std::cout << "I can sleep!" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        std::cout << "I can bark! Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;

    // Calling base class methods
    myDog.eat();
    myDog.sleep();

    // Calling derived class method
    myDog.bark();

    return 0;
}
