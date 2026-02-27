#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        vector<vector<int>> day(row, vector<int>(col, 0));
        
        for(int d = 0; d < cells.size(); ++d) {
            int r = cells[d][0] - 1;
            int c = cells[d][1] - 1;
            grid[r][c] = 1;
            day[r][c] = d + 1;
        }
        
        auto canCross = [&](int D) {
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            queue<pair<int, int>> q;
            
            for(int c = 0; c < col; ++c) {
                if(day[0][c] > D) {
                    q.push({0, c});
                    visited[0][c] = true;
                }
            }
            
            vector<int> dirs = {0, 1, 0, -1, 0};
            
            while(!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                if(r == row - 1) return true;
                
                for(int i = 0; i < 4; ++i) {
                    int nr = r + dirs[i];
                    int nc = c + dirs[i + 1];
                    
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && 
                       !visited[nr][nc] && day[nr][nc] > D) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };
        
        int left = 0, right = cells.size();
        while(left < right) {
            int mid = left + (right - left + 1) / 2;
            if(canCross(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};