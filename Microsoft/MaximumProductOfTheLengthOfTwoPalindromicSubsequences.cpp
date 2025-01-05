#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPal(string s){
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to explore all possible partitionings
    void recurse(string s, string s1, string s2, int ind, int& maxi, int n) {
        if (ind == n) {
            // When we reach the end of the string, check if both s1 and s2 are palindromes
            if (isPal(s1) && isPal(s2)) {
                maxi = max(maxi, (int)(s1.size() * s2.size()));
            }
            return;
        }

        // Choice 1: Do not include the current character in either of the two strings
        recurse(s, s1, s2, ind + 1, maxi, n);

        // Choice 2: Include the current character in s1
        s1.push_back(s[ind]);
        recurse(s, s1, s2, ind + 1, maxi, n);
        s1.pop_back();  // Backtrack

        // Choice 3: Include the current character in s2
        s2.push_back(s[ind]);
        recurse(s, s1, s2, ind + 1, maxi, n);
        s2.pop_back();  // Backtrack
    }

    // Main function to calculate the maximum product
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        int maxi = 0, n = s.size();
        recurse(s, s1, s2, 0, maxi, n);  // Starting from 0th index
        return maxi;
    }
};

// Driver code
int main() {
    Solution solution;
    string s;
    cin >> s;
    cout << solution.maxProduct(s) << endl;
    return 0;
}
