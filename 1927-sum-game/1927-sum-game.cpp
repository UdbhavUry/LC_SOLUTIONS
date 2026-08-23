class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        // Process left half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        // Process right half
        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // If total '?' is odd → Alice wins
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Check if Bob can balance
        int diff = leftSum - rightSum;
        int target = (rightQ - leftQ) / 2 * 9;

        return diff != target;
    }
};