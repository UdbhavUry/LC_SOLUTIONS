class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s;
        vector<int> s1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                s.push_back(nums[i]);
            } else {
                s1.push_back(nums[i]);
            }
        }
        int k = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = s[k];
                k++;
            } else {
                nums[i] = s1[r];
                r++;
            }
        }

        return nums;
    }
};