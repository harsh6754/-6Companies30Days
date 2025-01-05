#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    count[0] = 1;
    int odd = 0, result = 0;

    for (int num : nums) {
        odd += num % 2;
        if (count.find(odd - k) != count.end()) {
            result += count[odd - k];
        }
        count[odd]++;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << "Number of nice subarrays: " << numberOfSubarrays(nums, k) << endl;
    return 0;
}