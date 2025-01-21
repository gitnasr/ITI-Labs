#include <iostream>
#include <cstring>

using namespace std;
class Point
{
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int z)
    {
        this->x = this->y = z;
    }
    Point(int z, int q)
    {
        this->x = z;
        this->y = q;
    }
    void setX(int z)
    {
        this->x = z;
    }
    void setY(int z)
    {
        this->y = z;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
};

class Rectangle
{
    Point p1, p2;
    int length, width;

public:
    Rectangle(int x1, int y1, int x2, int y2)
    {
        length = abs(x2 - x1);
        width = abs(y2 - y1);
    }
    void setP1(int x, int y)
    {
        p1.setX(x);
        p2.setY(y);
        length = abs(p2.getX() - x);
        width = abs(p2.getY() - y);
    }
    void setP2(int x, int y)
    {
        p2.setX(x);
        p2.setY(y);
        length = abs(x - p1.getX());
        width = abs(y - p1.getY());
    }
    Point GetP1()
    {
        return p1;
    }
    Point GetP2()
    {
        return p2;
    }

    int Area()
    {
        return (length * width);
    }
};

class RectangleWithPointers
{
    Point *p1, *p2;
    int length, width;

public:
    RectangleWithPointers()
    {
        p1 = p2 = nullptr;
        length = width = 0;
    }
    RectangleWithPointers(Point *pt1, Point *pt2)
    {
        p1 = pt1;
        p2 = pt2;
        if (p1 != NULL && p2 != NULL)
        {
            length = abs(p2->getX() - p1->getX());
            width = abs(p2->getY() - p1->getY());
        }
        else
        {
            length = width = 0;
        }
    }
    void setP1(Point *pt1)
    {
        p1 = pt1;
    }
    void setP2(Point *pt2)
    {
        p2 = pt2;
    }
    Point getP1(Point *p1)
    {
        return *p1;
    }
    Point getP2(Point *p2)
    {
        return *p2;
    }

    int Area()
    {
        return (length * width);
    }
};

int main()
{
    Rectangle r1(20, 30, 40, 60);
    cout << r1.Area() << endl;

    Rectangle r2(20, 30, 10, 10);
    cout << r2.Area() << endl;

    Point p1(50, 20);
    Point p2(44, 100);
    RectangleWithPointers r3(&p1, &p2);

    cout << r3.Area() << endl;
}
