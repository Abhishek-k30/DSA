class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> graph(m, vector<int>(n, 0));
        
        
        for ( auto& wall : walls) {
            graph[wall[0]][wall[1]] = 2;  
        }
        for (const auto& guard : guards) {
            graph[guard[0]][guard[1]] = 3;  
        }
        
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
         
        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (const auto& dir : directions) {
                int nx = x, ny = y;
                while (true) {
                    nx += dir.first;
                    ny += dir.second;
                    
                    // Stop if out of bounds, a wall, or another guard
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || graph[nx][ny] == 2 || graph[nx][ny] == 3) {
                        break;
                    }
                    
                     
                    if (graph[nx][ny] == 0) {
                        graph[nx][ny] = 1;
                    }
                }
            }
        }
        
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] == 0) {
                    ++unguardedCount;
                }
            }
        }
        
        return unguardedCount;
    }
};
