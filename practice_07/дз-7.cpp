#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


struct Point
{
  double x;
  double y;
};

bool comp(const Point& p1, const Point& p2) // функция сравнения отношения координат точек
{
    Point start = {1, 1}; //костыльный старт
    if ((start.x/start.y) <= (p1.x/p1.y))
    {
       if ((start.x/start.y) <= (p2.x/p2.y)) 
       {
           return ((p1.x/p1.y) < (p2.x/p2.y));
       }
       else
       {
           return ((p2.x/p2.y) < (p1.x/p1.y));
       }
    }
    else
    {
        if ((start.x/start.y) <= (p2.x/p2.y))
        {
            return ((p2.x/p2.y) < (p1.x/p1.y));
        }
        else
        {
            return (((p2.x/p2.y) - (p1.x/p1.y)) < ((p1.x/p1.y) - (p2.x/p2.y)));
        }
    }
}

void sortPoints(vector<Point>& points) // функция сортировки всех точек вектора
{
  sort(points.begin(), points.end(), comp); 
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    vector<Point> points = 
    {
        {1, 1},
        {2, 2},
        {2, 0},
        {3, 1},
        {2, 1},
        {0, 3},
        {1, 3},
        {1, 5},
        {4, 3},
        {7, 9},
        {0, 2}
    };
    sortPoints(points);
    for (const Point& p : points) {
        cout << "(" << p.x << ", " << p.y << ")";
    }

    return 0;
}