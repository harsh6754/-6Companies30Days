#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = i; j < nums.size(); ++j){
            int last = -1, flag = 1;
            for(int k = 0; k < nums.size(); ++k){
                if(k >= i && k <= j) continue;
                if(last >= nums[k]){ flag = 0; break; }
                last = nums[k];
            }
            if(flag) ans++;
        }
    }
    return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution solution;
    int result = solution.incremovableSubarrayCount(nums);
    cout << result;
    return 0;
}
