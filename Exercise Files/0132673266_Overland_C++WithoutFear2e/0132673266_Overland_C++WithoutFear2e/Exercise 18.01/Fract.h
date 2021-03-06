#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;      // Numerator and denominator.
public:
    Fraction() {set(0, 1);}
    Fraction(int n, int d) {set(n, d);}
    Fraction(int n) {set(n, 1);}
    Fraction(const Fraction &src) {set(src.n, src.d); }

    void set(int n, int d) {num = n; den = d; normalize();}
    int get_num() const {return num;}
    int get_den() const {return den;}
    Fraction add(const Fraction &other);
    Fraction mult(const Fraction &other);
    Fraction operator+(const Fraction &other)
        {return add(other);}
    Fraction operator*(const Fraction &other)
        {return mult(other);}
    int operator==(const Fraction &other);
    friend ostream &operator<<(ostream &os, Fraction &fr);

protected:
    virtual void normalize();   // Put into standard form.
private:
    int gcf(int a, int b);     // Greatest Common Factor.
    int lcm(int a, int b);     // Lowest Common Denominator.
};
