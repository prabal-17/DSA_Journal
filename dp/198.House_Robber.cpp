class Solution {
public:
int solve(vector<int>& nums,int i)//Recursive 
{
    if(i>=nums.size())return 0;
    int steal=nums[i]+solve(nums,i+2);
    int skip=solve(nums,i+1);
    return max(skip,steal);
}
    int rob(vector<int>& nums) {
     return solve(nums,0);   
    }
};
class Solution {
public:
int arr[101];//only index is changing and lemgth of nums is 100 max
int solve(vector<int>& nums,int i)//Recursive 
{
    if(i>=nums.size())return 0;
    if(arr[i]!=-1)return arr[i];
    int steal=nums[i]+solve(nums,i+2);
    int skip=solve(nums,i+1);
    return arr[i]=max(skip,steal);
}
    int rob(vector<int>& nums) {
    memset(arr,-1,sizeof(arr));
     return solve(nums,0);   
    }
};
//Bottom up
class Solution {
public:
int arr[101];//only index is changing and lemgth of nums is 100 max

    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    vector<int> t(n+1);// t[i] store the max money robber can stole till house i
    t[0]=0;// no houses so zero money
    t[1]=nums[0];//first house so what it is in that is highest
    for(int i=2;i<=n;i++)
    {
        int steal=nums[i-1]+t[i-2];
        int skip=t[i-1];
        t[i]=max(steal,skip);

    }
     return t[n];   
    }
};