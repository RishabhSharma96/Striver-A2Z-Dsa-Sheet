// WITHOUT PRIORITY QUEUE
class Solution
{
    public:
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0 ;
        int j=0 ;
        int k=0 ;
        vector<int> merged(m+n) ;
        
        while( i<m && j<n ){
            
            if(nums1[i] < nums2[j]){
                merged[k] = nums1[i] ;
                k++ ; i++ ;
            }
            else if(nums1[i] > nums2[j]){
                merged[k] = nums2[j] ;
                k++ ; j++ ;
            }
            else if(nums1[i] == nums2[j]){
                merged[k] = nums2[j] ;
                k++ ; j++ ;
            } 
        }
        
        while(i<m){
            merged[k] = nums1[i] ;
            k++ ; i++ ;
        }
        while(j<n){
            merged[k] = nums2[j] ;
            k++ ; j++ ;
        }
        
        nums1 = merged ;
        
    }
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        
        for(int i=0 ; i<arr.size(); i++){
            merge(ans,ans.size(),arr[i],arr[i].size());
        }
        
        return ans;
    }
};

// WITH PRIORITY QUEUE  

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq ;
        // for -> {first_element, {array_index,element_index}}
        
        vector<int> ans;
        
        for(int i=0 ; i<K ; i++){
            pq.push({arr[i][0] , {i,0}});
        }
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop() ;
            
            int element = node.first;
            int arrIndex = node.second.first;
            int elementIndex = node.second.second;
            
            ans.push_back(element);
            if(elementIndex+1 < arr[arrIndex].size()){
                pq.push({arr[arrIndex][elementIndex+1],{arrIndex,elementIndex+1}});
            }
        }
        
        return ans;
    }
};