class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // If k is larger than the total elements, wrap it around
        k = k % total;
        
        // Create a result grid of the same dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the flat 1D index, shift it, and wrap around
                int new_index = (i * n + j + k) % total;
                
                // Convert 1D index back to 2D coordinates
                int new_row = new_index / n;
                int new_col = new_index % n;
                
                result[new_row][new_col] = grid[i][j];
            }
        }
        
        return result;
    }
};