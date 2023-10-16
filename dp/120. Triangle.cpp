Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Recursion+ meoization 
class Solution {
public:
int n;
int t[201][201];
int solve(int i,int j,vector<vector<int>>& triangle)
{
    if(i== n-1)return triangle[i][j];
    if(j>i)return 1e9;
    if(t[i][j]!=-1)return t[i][j];
    int down= triangle[i][j]+solve(i+1,j,triangle);
    int diagonal_right= triangle[i][j]+solve(i+1,j+1,triangle);
    return t[i][j]=min(down,diagonal_right);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,triangle);
    }
};
// tabulation
class Solution {
public:
int n;
    int minimumTotal(vector<vector<int>>& triangle) {
    n=triangle.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
     for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }
 for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];


            dp[i][j] = min(down, diagonal);
        }
    }

    
    return dp[0][0];
}
};
// space optimization
class Solution {
public:
int n;
    int minimumTotal(vector<vector<int>>& triangle) {
    n=triangle.size();
    vector<int>prev(n,0);
    vector<int>curr(n,0);


     for (int j = 0; j < n; j++) {
        prev[j] = triangle[n - 1][j];
    }
 for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];


            curr[j] = min(down, diagonal);
        }
        prev=curr;
    }

    
    return prev[0];
}
};