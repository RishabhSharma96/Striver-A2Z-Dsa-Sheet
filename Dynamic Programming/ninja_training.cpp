class Solution {
  public:
  
    int solve(vector<vector<int>>& points, int day, int prevDay, vector<vector<int>> & dp){
        
        if(dp[day][prevDay] != -1){
            return dp[day][prevDay] ;
        }
        
        if(day == 0){
            int maxPoints = -1e8;
            
            for(int task=0; task<3; task++){
                if(task != prevDay){
                    maxPoints = max(maxPoints,points[day][task]);
                }
            }
            return maxPoints;
        }
        
        int maxPoints = -1e8;
        for(int task=0; task<3; task++){
            if(task != prevDay){
                maxPoints = max(maxPoints,points[day][task] + solve(points,day-1,task,dp));
            }
        }
        
        return dp[day][prevDay] =  maxPoints;
        
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        
        // vector<vector<int>> dp(n, vector<int> (4,-1));
        // return solve(points,n-1,3,dp);
        
        
        vector<vector<int>> dp(n, vector<int> (4,0));
        
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1 ; day<n ; day++){
            for(int prevDay=0 ; prevDay<4 ;prevDay++){
                int maxPoints = -1e8;
                for(int task=0; task<3; task++){
                    if(task != prevDay){
                        maxPoints = max(maxPoints,points[day][task] + dp[day-1][task]);
                    }
                }
                dp[day][prevDay] =  maxPoints;
            }
        }
        return dp[n-1][3];
    }
};
