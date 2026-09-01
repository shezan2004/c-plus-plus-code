class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sr = i; sc = j; }
                else if (c == 'L') { litterIdx[i][j] = litterCount++; }
            }
        }

        if (litterCount == 0) return 0; // nothing to collect
        int fullMask = (1 << litterCount) - 1;

        int E1 = energy + 1;              // energy levels 0..energy
        int maskCount = 1 << litterCount;
        int posCount = m * n;
        long long totalStatesL = (long long)posCount * E1 * maskCount;
        int totalStates = (int)totalStatesL;

        vector<int> dist(totalStates, -1);

        auto encode = [&](int r, int c, int e, int mask) -> int {
            int pos = r * n + c;
            return ((pos * E1 + e) * maskCount) + mask;
        };

        int startCode = encode(sr, sc, energy, 0);
        dist[startCode] = 0;

        queue<int> q;
        q.push(startCode);

        static const int dr[4] = {-1, 1, 0, 0};
        static const int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int code = q.front(); q.pop();
            int d = dist[code];

            int mask = code % maskCount;
            int tmp = code / maskCount;
            int e = tmp % E1;
            int pos = tmp / E1;
            int r = pos / n;
            int c = pos % n;

            if (mask == fullMask) return d;
            if (e == 0) continue; // stuck here, can't move further

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char ch = classroom[nr][nc];
                if (ch == 'X') continue;

                int ne = e - 1;
                if (ch == 'R') ne = energy; // full reset regardless of current level

                int nmask = mask;
                if (ch == 'L') {
                    int idx = litterIdx[nr][nc];
                    if (idx >= 0) nmask |= (1 << idx);
                }

                int ncode = encode(nr, nc, ne, nmask);
                if (dist[ncode] == -1) {
                    dist[ncode] = d + 1;
                    q.push(ncode);
                }
            }
        }

        return -1;
    }
};