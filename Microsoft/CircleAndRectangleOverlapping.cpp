#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1 , min(x2,xCenter));
        int nearestY = max(y1 , min(y2,yCenter));

        int dist = (nearestX - xCenter)*(nearestX - xCenter) + (nearestY - yCenter)*(nearestY - yCenter);
        return dist <= radius*radius;
    }
};
int main() {
    int radius, xCenter, yCenter, x1, x2, y1, y2;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "Enter the center of the circle from x direction: ";
    cin >> xCenter;

    cout << "Enter the center of the circle from y direction: ";
    cin >> yCenter;

    cout << "Enter the x coordinate of the first point of the rectangle: ";
    cin >> x1;

    cout << "Enter the y coordinate of the first point of the rectangle: ";
    cin >> y1;

    cout << "Enter the x coordinate of the second point of the rectangle: ";
    cin >> x2;

    cout << "Enter the y coordinate of the second point of the rectangle: ";
    cin >> y2;

    Solution solution;
    bool result = solution.checkOverlap(radius, xCenter, yCenter, x1, x2, y1, y2);
    cout << (result ? "true" : "false");

    return 0;
}
