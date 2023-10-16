//Recursion  top down
class Solution {
public:
    int solve(int n)
    {
        if(n==0) return 1;
        if(n<0)return 0;
        int one_step=solve(n-1);
        int two_step=solve(n-2);
        return one_step+two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

//Memoization 
class Solution {
public:
int dp[46];
    int solve(int n)
    {
        if(n==0) return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int one_step=solve(n-1);
        int two_step=solve(n-2);
        return dp[n]=one_step+two_step;
    }
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
//Bottom UP
int climbStairs(int n) {
        if(n==1||n==2||n==3)return n;

        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }