class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int freshCount = 0;  
        int minutes = 0;    
        
        queue<pair<int, int>> rotten;  
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
       
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();  
            for (int i = 0; i < size; i++) {
                int row = rotten.front().first;
                int col = rotten.front().second;
                rotten.pop();
                
                for (int dir = 0; dir < 4; dir++) {
                    int newRow = row + dr[dir];
                    int newCol = col + dc[dir];
                    
                    
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;  
                        freshCount--;  
                        rotten.push({newRow, newCol}); 
                    }
                }
            }
            minutes++;  
        }
 
        return (freshCount == 0) ? minutes : -1;
    }
};
