#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // max_score initialized to -1 (unreachable)
        vector<vector<int>> max_score(n, vector<int>(n, -1));
        vector<vector<int>> path_count(n, vector<int>(n, 0));
        
        // Base case: Starting point 'S'
        max_score[n-1][n-1] = 0;
        path_count[n-1][n-1] = 1;
        
        // Directions to look at: Down, Right, Down-Right
        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};
        
        // Iterate backwards from bottom-right to top-left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip the starting cell since it's already initialized
                if (i == n - 1 && j == n - 1) continue;
                // Skip obstacles
                if (board[i][j] == 'X') continue;
                
                int best_score = -1;
                int current_paths = 0;
                
                // Check all 3 possible previous steps
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if (ni < n && nj < n && max_score[ni][nj] != -1) {
                        if (max_score[ni][nj] > best_score) {
                            best_score = max_score[ni][nj];
                            current_paths = path_count[ni][nj];
                        } else if (max_score[ni][nj] == best_score) {
                            current_paths = (current_paths + path_count[ni][nj]) % MOD;
                        }
                    }
                }
                
                // If at least one valid path reaches this cell
                if (best_score != -1) {
                    int current_val = (board[i][j] == 'E' || board[i][j] == 'S') ? 0 : (board[i][j] - '0');
                    max_score[i][j] = best_score + current_val;
                    path_count[i][j] = current_paths;
                }
            }
        }
        
        // If 'E' at (0,0) is unreachable, return [0, 0]
        if (max_score[0][0] == -1) {
            return {0, 0};
        }
        
        return {max_score[0][0], path_count[0][0]};
    }
};