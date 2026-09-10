class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    vector<int> v(n + m);

    for (int i = 0; i < n; i++) {
        v[i] = nums1[i];
    }
    for (int i = 0; i < m; i++) {
        v[n + i] = nums2[i];
    }

    sort(v.begin(), v.end());

    int l = v.size();

    if (l % 2 == 0) {
        return (v[l/2 - 1] + v[l/2]) / 2.0;  // fix
    } else {
        return v[l/2];  // fix
    }
}
};