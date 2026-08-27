class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n);
        int k = 0;
        int r = 1;
       
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                s[k]=nums[i];
                k+=2;
            } else {
                s[r]=nums[i];
                r+=2;
            }
        }
        
        return s;
    }
};