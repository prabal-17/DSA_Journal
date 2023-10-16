Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//  recursion + moemoization 
class Solution {
public:
int n,m;
int t[201][201];
int solve(int i,int j,vector<vector<int>>& grid)
{
    if(i==0&& j==0)return grid[i][j];
    if(i<0 ||j<0)return 1e9;
    if(t[i][j]!=-1)return t[i][j];
    int up= grid[i][j]+solve(i-1,j,grid);
    int left= grid[i][j]+solve(i,j-1,grid);
    return t[i][j]=min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(m-1,n-1,grid);
    }
};
// tabulation 
class Solution {
public:
int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int t[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { if (i == 0 && j == 0)
                t[i][j] = grid[i][j]; 
            else {
                int up = grid[i][j];
                if (i > 0)
                    up += t[i - 1][j]; 
                else
                    up += 1e9; 

                int left = grid[i][j];
                if (j > 0)
                    left += t[i][j - 1]; 
                else
                    left += 1e9; 

                t[i][j] = min(up, left);
            }
            }
        }
        return t[m-1][n-1];
    }
};
// space optimization
class Solution {
public:
int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<int>prev(n);
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n);
            for(int j=0;j<n;j++)
            { if (i == 0 && j == 0)
                curr[j] = grid[i][j]; 
            else {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j]; 
                else
                    up += 1e9; 

                int left = grid[i][j];
                if (j > 0)
                    left +=curr[j - 1]; 
                else
                    left += 1e9; 

                curr[j] = min(up, left);
            }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};

