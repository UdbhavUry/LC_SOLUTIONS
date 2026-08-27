class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int even=0;
        int odd=1;
        for(auto n:nums){
            if(n<0){
                ans[odd]=n;
                odd+=2;
            }
            else{
                ans[even]=n;
                even+=2;
            }
        }
        return ans;
    }
};