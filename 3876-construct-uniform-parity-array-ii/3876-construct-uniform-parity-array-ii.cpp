class Solution { 
public: 
    bool uniformArray(vector<int>& nums1) { 
        int minOdd = INT_MAX, minEven = INT_MAX;
        
        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }
        
        // If no odd exists → all are even → already valid
        if (minOdd == INT_MAX) return true;
        
        // If no even exists → all are odd → already valid
        if (minEven == INT_MAX) return true;
        
        // Check if we can convert all to odd
        return minOdd < minEven;
    } 
};