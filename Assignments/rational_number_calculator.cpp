#include <iostream>
using namespace std;
class Rational
{
    int numerator;
    int denominator;

    int gcd (int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void reduce ()
    {
        int div = gcd (numerator, denominator);
        numerator /= div;
        denominator /= div;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }    
    }

    public:
    Rational (int num = 0, int den = 1)
    {
        if (den == 0)
        {
            cout << "Error Occured! Denominator cannot be zero. Setting it to 1 by default." << endl;
            den = 1;
        }
        numerator = num;
        denominator = den;
        reduce();
    }
    Rational add (Rational r)
    {
        int num = (numerator * r.denominator) + (r.numerator * denominator);
        int den = denominator * r.denominator;
        return Rational (num, den);
    }
    Rational subtract (Rational r)
    {
        int num = (numerator * r.denominator) - (r.numerator * denominator);
        int den = denominator * r.denominator;
        return Rational (num, den);
    }
    Rational multiply (Rational r)
    {
        int num = numerator * r.numerator;
        int den = denominator * r.denominator;
        return Rational (num, den);
    }
    Rational divide (Rational r)
    {
        if (r.numerator == 0)
        {
            cout << "Error Occured! Fraction cannot be divided by zero." << endl;
            return Rational ();
        }
        int num = numerator * r.denominator;
        int den = denominator * r.numerator;
        return Rational (num, den);
    }

    void printFraction ()
    {
        cout << numerator << "/" << denominator << endl;
    }
    void printDecimal()
    {
        cout << (double)numerator / denominator << endl;
    }
};

int main()
{
    Rational r1 (2, 4);
    Rational r2 (6, 8);

    cout << "Rational Number 1: "; r1.printFraction ();
    cout << "Decimal: "; r1.printDecimal (); cout << endl;

    cout << "Rational Number 2: "; r2.printFraction ();
    cout << "Decimal: "; r2.printDecimal (); cout << endl;

    Rational sum = r1.add (r2);
    cout << "Sum: "; sum.printFraction ();
    cout << "Decimal: "; sum.printDecimal (); cout << endl;

    Rational diff = r1.subtract (r2);
    cout << "Difference: "; diff.printFraction ();
    cout << "Decimal: "; diff.printDecimal (); cout << endl;

    Rational product = r1.multiply (r2);
    cout << "Product: "; product.printFraction ();
    cout << "Decimal: "; product.printDecimal (); cout << endl;

    Rational quotient = r1.divide (r2);
    cout << "Quotient: "; quotient.printFraction ();
    cout << "Decimal: "; quotient.printDecimal (); cout << endl;

    return 0;
}
