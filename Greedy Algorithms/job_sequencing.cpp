/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comparator(Job job1, Job job2){
        return job1.profit > job2.profit ;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparator);
        
        int maxDeadline = arr[0].dead;
        for(int i=0; i<n ; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> jobSequence(maxDeadline+1, -1);
        
        int jobCount=0, totalProfit=0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=arr[i].dead ; j>=1 ; j--){
                if(jobSequence[j] == -1){
                    jobSequence[j] = i;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {{jobCount, totalProfit}} ;
    } 
};