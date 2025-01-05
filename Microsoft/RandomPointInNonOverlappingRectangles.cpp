#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> rects;
    vector<int> areas;
    int totalArea;

public:
    Solution(vector<vector<int>>& rects) : rects(rects), totalArea(0) {
        srand(time(0));
        for (const auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalArea += area;
            areas.push_back(totalArea);
        }
    }

    vector<int> pick() {
        int randArea = rand() % totalArea;
        int rectIndex = lower_bound(areas.begin(), areas.end(), randArea + 1) - areas.begin();
        const auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};

int main() {
    vector<vector<int>> rects = {{1, 1, 5, 5}, {10, 10, 13, 13}, {20, 20, 25, 25}};
    Solution solution(rects);

    for (int i = 0; i < 10; ++i) {
        vector<int> point = solution.pick();
        cout << "Random Point: (" << point[0] << ", " << point[1] << ")" << endl;
    }

    return 0;
}