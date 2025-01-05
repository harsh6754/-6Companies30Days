#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void wiggleSort(vector<int>& nums){
        int size = nums.size();
        if(size<=1){
            return;
        }
        sort(nums.begin(),nums.end());
        vector<int>temp(size);
        int i = 1;
        int j = size-1;
        while(i<size){
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        i = 0;
        while(i<size){
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        nums = temp;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    Solution solution;
    solution.wiggleSort(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }

    return 0;
}