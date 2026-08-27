class Solution {
public:
   bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> m1(256, -1); // s -> t
    vector<int> m2(256, -1); // t -> s

    for (int i = 0; i < s.size(); i++) {
        if (m1[s[i]] == -1 && m2[t[i]] == -1) {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else {
            if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
                return false;
        }
    }
    return true;
}
};