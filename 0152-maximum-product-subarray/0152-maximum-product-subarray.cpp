class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // Agar number negative hai, swap kar do
            if (num < 0) {
                swap(maxProd, minProd);
            }

            // Update max and min product
            maxProd = max(num, num * maxProd);
            minProd = min(num, num * minProd);

            // Update answer
            ans = max(ans, maxProd);
        }

        return ans;
    }
};