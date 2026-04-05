#include <iostream>
using namespace std;

/* ================= DISTANCE CLASS ================= */

class Distance
{
    int feet;
    double inches;

public:
    Distance(int f = 0, double i = 0)
    {
        feet = f;
        inches = i;
        normalize();
    }

    void normalize()
    {
        if (inches >= 12)
        {
            feet += int(inches) / 12;
            inches = inches - (int(inches) / 12) * 12;
        }
        else if (inches < 0)
        {
            while (inches < 0 && feet > 0)
            {
                inches += 12;
                feet--;
            }
            if (feet < 0) feet = inches = 0;
        }
    }

    void show() const { cout << feet << " ft " << inches << " in\n"; }

    Distance operator+(const Distance &d) const
    {
        return Distance(feet + d.feet, inches + d.inches);
    }

    Distance operator-(const Distance &d) const
    {
        int total1 = feet * 12 + inches;
        int total2 = d.feet * 12 + d.inches;
        int diff = max(0, total1 - total2);
        return Distance(diff / 12, diff % 12);
    }
};

/* ================= POLYNOMIAL CLASS ================= */

class Polynomial
{
    int coef[10];

public:
    Polynomial()
    {
        for (int i = 0; i < 10; i++) coef[i] = 0;
    }

    void setCoefficient(int c, int exp)
    {
        if (exp < 10) coef[exp] = c;
    }

    void display() const
    {
        for (int i = 9; i >= 0; i--)
            if (coef[i] != 0) cout << coef[i] << "x^" << i << " ";
        cout << endl;
    }

    Polynomial operator+(const Polynomial &p) const
    {
        Polynomial r;
        for (int i = 0; i < 10; i++) r.coef[i] = coef[i] + p.coef[i];
        return r;
    }
};

/* ================= MAIN ================= */

int main()
{
    cout << "=== Distance Operations ===\n";
    Distance d1(5, 8), d2(3, 9);
    Distance d3 = d1 + d2;
    d3.show();

    cout << "\n=== Polynomial Operations ===\n";
    Polynomial p1, p2;
    p1.setCoefficient(2, 3);
    p2.setCoefficient(1, 3);
    Polynomial sum = p1 + p2;
    sum.display();

    return 0;
}
