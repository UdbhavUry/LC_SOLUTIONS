class Solution {
public:
   string shortestBeautifulSubstring(string s, int k) {
    int n = s.size();
    int left = 0, count1 = 0;

    int minLen = INT_MAX;
    string ans = "";

    for (int right = 0; right < n; right++) {
        if (s[right] == '1') count1++;

        while (count1 > k) {
            if (s[left] == '1') count1--;
            left++;
        }

        if (count1 == k) {
            // shrink to remove leading zeros
            while (s[left] == '0') left++;

            int len = right - left + 1;
            string temp = s.substr(left, len);

            if (len < minLen) {
                minLen = len;
                ans = temp;
            } else if (len == minLen && temp < ans) {
                ans = temp;
            }
        }
    }

    return ans;
    }
};