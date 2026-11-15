class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        // {finishTime, serverId}, min-heap by finish time
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<>> busy;

        vector<int> cnt(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            // free up servers that finished by now
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }
            if (freeServers.empty()) continue; // dropped

            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin(); // wrap around

            int id = *it;
            freeServers.erase(it);
            cnt[id]++;
            busy.push({(long long)arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};