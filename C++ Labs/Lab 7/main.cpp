using namespace std;
#include <iostream>
class Shape
{
protected:
    int d1, d2;

public:
    Shape()
    {
        d1 = 1;
        d2 = 0;
    }
    Shape(int d)
    {
        d1 = d2 = d;
    }
    Shape(int d, int dd)
    {
        d1 = d;
        d2 = dd;
    }
    void setD1(int d)
    {
        d1 = d;
    }
    void setD2(int d)
    {
        d2 = d;
    }
    int getD1()
    {
        return d1;
    }
    int getD2()
    {
        return d2;
    }
    virtual float Area() = 0;
};
class Circle : public Shape
{
public:
    Circle() {}
    Circle(int r) : Shape(r) {}
    float Area()
    {
        return (3.14 * d1 * d2);
    }
};

class Rectangle : public Shape
{
public:
    Rectangle() {}
    Rectangle(int l, int h) : Shape(l, h) {}
    float Area()
    {
        return (1.0 * d1 * d2);
    };
};

class Triangle : public Shape
{
public:
    Triangle() {}
    Triangle(int l, int h) : Shape(l, h) {}
    float Area()
    {
        return (0.5 * d1 * d2);
    };
};

class Square : public Rectangle
{
public:
    Square() {}
    Square(int l) : Rectangle(l, l) {}
};

class GeoShape
{
    Shape **PointerOfShape;
    int size = 0;

public:
    GeoShape(Shape **ArrayOfShapes, int s)
    {
        PointerOfShape = ArrayOfShapes;
        this->size = s;
    };
    float TotalArea()
    {
        float sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += PointerOfShape[i]->Area();
        }
        return sum;
    };
};

int main()
{
    Square S1(5);
    Square S2(6);
    Rectangle R1(5, 7);
    Triangle T1(8, 3);
    Shape *arr[4] = {
        &S1,
        &S2,
        &R1,
        &T1,
    };
    GeoShape geo(arr, 4);
    cout << geo.TotalArea() << endl;
}