#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    point p1, p2;
    cout << "Enter coordinates of point 1: ";
    cin >> p1.x >> p1.y;
    cout << "Enter coordinates of point 2: ";
    cin >> p2.x >> p2.y;
    float distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    cout << "Distance between the two points: " << distance << endl;
    return 0;
}