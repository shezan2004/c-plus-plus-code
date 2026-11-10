class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        using pii = pair<int,int>;
        using tiii = tuple<long long,int,int>;

        // free servers: (weight, index)
        priority_queue<pii, vector<pii>, greater<pii>> freeQ;
        // busy servers: (free time, weight, index)
        priority_queue<tiii, vector<tiii>, greater<tiii>> busyQ;

        for (int i = 0; i < n; i++) freeQ.push({servers[i], i});

        vector<int> ans(m);
        long long t = 0;

        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);

            // release servers that are free by time t
            while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {
                auto [ft, w, idx] = busyQ.top();
                busyQ.pop();
                freeQ.push({w, idx});
            }

            // no free server: jump to the earliest time one frees up
            if (freeQ.empty()) {
                t = get<0>(busyQ.top());
                while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {
                    auto [ft, w, idx] = busyQ.top();
                    busyQ.pop();
                    freeQ.push({w, idx});
                }
            }

            auto [w, idx] = freeQ.top();
            freeQ.pop();
            ans[j] = idx;
            busyQ.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};