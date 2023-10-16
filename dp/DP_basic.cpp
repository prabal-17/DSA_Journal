// Fibonacci
// TC-> O(2^n) 
int dp[n+1];// for memoization 
int fun(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fun(n-1)+fun(n-2);
}
//Bottom UP TC-> O(n) SC->O(N)
int fib(int n) {
        vector<int> dp(n+1,-1);
         dp[0]=0;
         dp[1]=1;
        for(int i=2;i<=n;i++)
        {
          dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
    //OPtimized TC-> O(n) SC->O(1)
int fib(int n) 
{
        int a=0;
        int b=1;
        for(int i=1;i<n;i++)
        {
          c=a+b;
          a=b;
          b=c;
        }
        return c;
    }