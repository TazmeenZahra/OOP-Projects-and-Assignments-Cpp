#include <iostream>
using namespace std;

class Circle
{
    double radius;
    double x;
    double y;

public:
    Circle() : radius(0), x(0), y(0) {}

    Circle(double r, double x_cord, double y_cord)
    {
        radius = r;
        x = x_cord;
        y = y_cord;
    }

    double area(double pi) { return pi * radius * radius; }
    double circumference(double pi) { return 2 * pi * radius; }

    void print()
    {
        cout << "\n--- Circle Details ---\n";
        cout << "Center: (" << x << ", " << y << ")\n";
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle
{
    int length;
    int width;

public:
    Rectangle() : length(1), width(1) {}

    void set(int l, int w)
    {
        length = l;
        width = w;
    }

    int area() { return length * width; }
    int perimeter() { return 2 * (length + width); }

    void draw()
    {
        cout << "\nRectangle Drawing:\n";
        for (int i = 1; i <= length; i++)
        {
            for (int j = 1; j <= width; j++)
            {
                if (i == 1 || i == length || j == 1 || j == width)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    const double pi = 3.14;

    Circle c(5.4, 2.2, 3.1);
    c.print();
    cout << "Area: " << c.area(pi) << endl;
    cout << "Circumference: " << c.circumference(pi) << endl;

    Rectangle r;
    r.set(4, 9);
    cout << "\n--- Rectangle Details ---\n";
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    r.draw();

    return 0;
}
