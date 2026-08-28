class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // Step 1: feasibility
        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }
        if (odd > 1) return "";

        vector<int> half(26);
        for (int i = 0; i < 26; i++) half[i] = freq[i] / 2;

        int halfLen = n / 2;
        string left = "";

        function<bool(int, bool)> dfs = [&](int pos, bool greater) {
            if (pos == halfLen) {
                // Build full palindrome and check final condition
                string right = left;
                reverse(right.begin(), right.end());

                string full;
                if (n % 2) full = left + string(1, mid) + right;
                else full = left + right;

                return full > target;
            }

            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                char ch = 'a' + c;

                // If still equal, enforce lex condition
                if (!greater && ch < target[pos]) continue;

                // choose
                half[c]--;
                left.push_back(ch);

                bool newGreater = greater || (ch > target[pos]);

                if (dfs(pos + 1, newGreater)) return true;

                // backtrack
                half[c]++;
                left.pop_back();
            }
            return false;
        };

        if (!dfs(0, false)) return "";

        // build answer
        string right = left;
        reverse(right.begin(), right.end());

        if (n % 2) return left + string(1, mid) + right;
        return left + right;
    }
};