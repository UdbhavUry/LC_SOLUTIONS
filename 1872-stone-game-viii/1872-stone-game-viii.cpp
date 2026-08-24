class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Prefix sums
        vector<long long> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        
        // Step 2: DP (optimized to O(1) space)
        long long dp = prefix[n - 1];  // dp[n-1]
        
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }
        
        return (int)dp;
    }
};