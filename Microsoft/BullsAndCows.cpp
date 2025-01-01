#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> secretCount(10, 0), guessCount(10, 0);
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            cows += min(secretCount[i], guessCount[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    string secret;
    string guess;
    getline(cin,secret);
    getline(cin,guess);

    Solution solution;
    string result = solution.getHint(secret,guess);
    cout<<result;

    return 0;
}