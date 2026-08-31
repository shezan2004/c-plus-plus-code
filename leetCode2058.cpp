class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, lastIdx = -1, minDist = INT_MAX;
        int idx = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - lastIdx);
                }
                lastIdx = idx;
            }
            prev = curr;
            curr = next;
            idx++;
        }

        if (firstIdx == -1 || firstIdx == lastIdx) {
            return {-1, -1};
        }

        int maxDist = lastIdx - firstIdx;
        return {minDist, maxDist};
    }
};