#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mpp;
        for(int i=0;i+10 <= s.length();i++){
            mpp[s.substr(i,10)]++;
        }

        for(auto& i:mpp){
            if(i.second > 1){
                v.push_back(i.first);
            }
        }

        return v;
        
    }
};

int main(){
    string s;
    getline(cin,s);

    Solution solution;
    vector<string>result = solution.findRepeatedDnaSequences(s);
    cout<<"{";
    for(auto x : result){
        cout<<x<<",";
    }
    cout<<"}";

    return 0;
}