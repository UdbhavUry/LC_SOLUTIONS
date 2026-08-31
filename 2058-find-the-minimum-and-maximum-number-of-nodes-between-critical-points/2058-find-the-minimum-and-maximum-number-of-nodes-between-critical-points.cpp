/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        vector<int> critical;

        while (curr->next) {
            ListNode* next = curr->next;

            // Check for local maxima or minima
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(index);
            }

            prev = curr;
            curr = next;
            index++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};