#include <iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        cout << c.real << " + " << c.imag << "i";
        return out;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    bool operator==(const Complex& c) {
        return real == c.real && imag == c.imag;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;

    cout << "\nAddition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;

    if (c1 == c2)
        cout << "Both complex numbers are equal.\n";
    else
        cout << "Complex numbers are not equal.\n";

    return 0;
}