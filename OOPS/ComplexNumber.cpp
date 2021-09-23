#include <iostream>
using namespace std;

class ComplexNumber {
    private:
        int a;
        int b;
    
    public:
        ComplexNumber (int a, int b) {
            this -> a = a;
            this -> b = b;
        }

        void plus(ComplexNumber const &f2) {
            a = a + f2.a;
            b = b + f2.b;
        }

        void multiply(ComplexNumber const &f2) {
            int real = a * f2.a - b * f2.b;
            int img = a * f2.b + b * f2.a;

            a = real;
            b = img;
        }

        void print() {
            cout << a << " + i" << b << endl;
        }
};

int main () {
    int a, b;
    cin >> a >> b;
    ComplexNumber c1(a, b);

    int x, y;
    cin >> x >> y;
    ComplexNumber c2(x,y);

    int choice;
    cin >> choice;

    if (choice == 1)
        c1.plus(c2);
    else if (choice == 2)
        c1.multiply(c2);

    c1.print();
    c2.print();

    return 0;
}