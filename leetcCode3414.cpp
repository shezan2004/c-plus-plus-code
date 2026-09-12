class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b){
            return intervals[a][0] < intervals[b][0];
        });

        vector<long long> L(n), R(n), W(n);
        vector<int> orig(n);
        for (int i = 0; i < n; i++) {
            L[i] = intervals[order[i]][0];
            R[i] = intervals[order[i]][1];
            W[i] = intervals[order[i]][2];
            orig[i] = order[i];
        }

        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(L.begin(), L.end(), R[i]) - L.begin();
        }

        const int K = 4;
        vector<array<long long, K+1>> score(n+1);
        vector<array<array<int,4>, K+1>> lst(n+1);
        vector<array<int, K+1>> len(n+1);

        for (int k = 0; k <= K; k++) {
            score[n][k] = 0;
            len[n][k] = 0;
        }

        auto better = [&](long long sc1, const array<int,4>& l1, int len1,
                           long long sc2, const array<int,4>& l2, int len2) -> bool {
            if (sc1 != sc2) return sc1 > sc2;
            int m = min(len1, len2);
            for (int i = 0; i < m; i++) {
                if (l1[i] != l2[i]) return l1[i] < l2[i];
            }
            return len1 < len2;
        };

        for (int i = n-1; i >= 0; i--) {
            score[i][0] = 0;
            len[i][0] = 0;
            for (int k = 1; k <= K; k++) {
                long long skipScore = score[i+1][k];
                const array<int,4>& skipList = lst[i+1][k];
                int skipLen = len[i+1][k];

                int nx = nxt[i];
                long long takeScore = W[i] + score[nx][k-1];
                array<int,4> takeList = lst[nx][k-1];
                int takeLen = len[nx][k-1];

                int insertPos = takeLen;
                for (int p = 0; p < takeLen; p++) {
                    if (takeList[p] > orig[i]) { insertPos = p; break; }
                }
                for (int p = takeLen; p > insertPos; p--) takeList[p] = takeList[p-1];
                takeList[insertPos] = orig[i];
                takeLen += 1;

                if (better(takeScore, takeList, takeLen, skipScore, skipList, skipLen)) {
                    score[i][k] = takeScore;
                    lst[i][k] = takeList;
                    len[i][k] = takeLen;
                } else {
                    score[i][k] = skipScore;
                    lst[i][k] = skipList;
                    len[i][k] = skipLen;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < len[0][K]; i++) result.push_back(lst[0][K][i]);
        return result;
    }
};