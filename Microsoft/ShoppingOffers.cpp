#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Memoization map to store results for a given state
        unordered_map<string, int> memo;

        // Function to convert `needs` vector into a unique string (state representation)
        auto needsToString = [](const vector<int>& needs) {
            string res = "";
            for (int x : needs) {
                res += to_string(x) + ",";
            }
            return res;
        };

        // Helper function to calculate the minimum cost recursively
        function<int(vector<int>&)> dfs = [&](vector<int>& curNeeds) -> int {
            string state = needsToString(curNeeds);
            if (memo.count(state)) {
                return memo[state];
            }

            // Base case: If no items are needed, cost is 0
            int minCost = 0;
            for (int i = 0; i < curNeeds.size(); i++) {
                minCost += curNeeds[i] * price[i];
            }

            // Try to apply each special offer
            for (auto& offer : special) {
                vector<int> newNeeds = curNeeds;
                bool valid = true;
                for (int i = 0; i < curNeeds.size(); i++) {
                    if (newNeeds[i] < offer[i]) { // If the offer cannot be applied
                        valid = false;
                        break;
                    }
                    newNeeds[i] -= offer[i]; // Apply the offer
                }

                if (valid) {
                    minCost = min(minCost, offer.back() + dfs(newNeeds));
                }
            }

            // Memoize the result
            memo[state] = minCost;
            return minCost;
        };

        return dfs(needs);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> special(m, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> special[i][j];
        }
    }

    vector<int> needs(n);
    for (int i = 0; i < n; i++) {
        cin >> needs[i];
    }

    Solution sol;
    cout << sol.shoppingOffers(price, special, needs) << endl;

    return 0;
}
