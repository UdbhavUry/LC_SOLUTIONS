class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        long long tflowers =1ll* m * k;
        if (tflowers > n) {
            return -1;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0;
            int bouquets = 0;
            for (int bloom : bloomDay) {
                if (bloom <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
         

            if (bouquets >= m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};