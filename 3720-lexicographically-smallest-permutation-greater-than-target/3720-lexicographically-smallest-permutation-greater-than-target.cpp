

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        return dfs(0, freq, target, "");
    }

    string dfs(int i, vector<int>& freq, string& target, string curr) {
        if (i == target.size()) return "";

        for (int c = 0; c < 26; c++) {
            if (freq[c] == 0) continue;

            char ch = c + 'a';
            if (ch < target[i]) continue;

            // choose
            freq[c]--;

            if (ch > target[i]) {
                // fill rest smallest
                string ans = curr + ch;
                for (int j = 0; j < 26; j++) {
                    ans += string(freq[j], char(j + 'a'));
                }
                return ans;
            }

            // ch == target[i]
            string res = dfs(i + 1, freq, target, curr + ch);
            if (res != "") return res;

            // backtrack
            freq[c]++;
        }

        return "";
    }
};