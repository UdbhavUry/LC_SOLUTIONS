class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Pair value with index
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        
        // Step 2: Sort by value
        sort(arr.begin(), arr.end());
        
        vector<int> res(n);
        
        int i = 0;
        while (i < n) {
            int j = i;
            vector<int> values;
            vector<int> indices;
            
            // Step 3: Build group
            while (j < n && (j == i || arr[j].first - arr[j - 1].first <= limit)) {
                values.push_back(arr[j].first);
                indices.push_back(arr[j].second);
                j++;
            }
            
            // Step 4: Sort indices
            sort(indices.begin(), indices.end());
            
            // Step 5: Assign smallest values to smallest indices
            for (int k = 0; k < values.size(); k++) {
                res[indices[k]] = values[k];
            }
            
            i = j;
        }
        
        return res;
    }
};