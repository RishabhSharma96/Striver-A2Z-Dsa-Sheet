class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq ;
        
        for(long long i=0 ; i<n ; i++){
            pq.push(arr[i]);
        }
        
        while(pq.size() != 1){
            long long ropeCost1 = pq.top();
            pq.pop() ;
            long long ropeCost2 = pq.top();
            pq.pop() ;
            
            cost += (ropeCost1 + ropeCost2) ;
            pq.push(ropeCost1 + ropeCost2);
        }
        return cost ;
    }
};