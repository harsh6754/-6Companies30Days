#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        
        // Step 1: Sort envelopes
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        // Step 2: Extract heights and find LIS
        vector<int> heights;
        for (auto& env : envelopes) {
            heights.push_back(env[1]);
        }

        // Step 3: Apply binary search to find LIS on heights
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }

        return lis.size();
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> envelopes(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>envelopes[i][0];
        cin>>envelopes[i][1];
    }
    Solution solution;
    int result = solution.maxEnvelopes(envelopes);
    cout<<result;
    return 0;
}