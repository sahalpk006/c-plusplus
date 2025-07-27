#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void calculateArea() = 0;
    virtual ~Shape() {
        cout << name << " destroyed.\n";
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
    float length, breadth;
public:
    Rectangle(float l, float b) : Shape("Rectangle"), length(l), breadth(b) {}
    void calculateArea() override {
        cout << "Area of Rectangle = " << length * breadth << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
    float radius;
public:
    Circle(float r) : Shape("Circle"), radius(r) {}
    void calculateArea() override {
        cout << "Area of Circle = " << 3.14159 * radius * radius << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
    float base, height;
public:
    Triangle(float b, float h) : Shape("Triangle"), base(b), height(h) {}
    void calculateArea() override {
        cout << "Area of Triangle = " << 0.5 * base * height << endl;
    }
};

int main() {
    Shape* shapes[3];

    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(4.0);
    shapes[2] = new Triangle(6.0, 2.0);

    for (int i = 0; i < 3; ++i) {
        shapes[i]->calculateArea();
    }

    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}