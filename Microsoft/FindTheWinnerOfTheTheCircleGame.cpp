#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findTheWinner(int n, int k){
        int winner = 0;
        for(int i=1;i<=n;i++){
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};
int main(){
    int n,k;
    cin>>n;
    cin>>k;

    Solution solution;
    int result = solution.findTheWinner(n,k);
    cout<<result;

    return 0;
}