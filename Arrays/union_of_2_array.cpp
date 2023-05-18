class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>ans;
        
        int i=0 , j=0 ;
        
        if(arr1[0] > arr2[0]){
            ans.push_back(arr2[0]);
            j++;
        }
        else{
            ans.push_back(arr1[0]);
            i++;
        }
        
        int k=0 ;
        
        while(i<n && j<m){
            if(arr1[i] < arr2[j]){
                if(arr1[i] == ans[k]){
                    i++;
                }
                else{
                    ans.push_back(arr1[i]);
                    i++; k++;
                }
            }
            else{
                if(arr2[j] == ans[k]){
                    j++;
                }
                else{
                    ans.push_back(arr2[j]);
                    j++; k++;
                }
            }
        }
        
        while(i<n){
            if(arr1[i] == ans[k]){
                i++;
            }
            else{
                ans.push_back(arr1[i]);
                i++; k++;
            }
        }
        
        while(j<m){
            if(arr2[j] == ans[k]){
                j++;
            }
            else{
                ans.push_back(arr2[j]);
                j++; k++;
            }
        }
        return ans;
    }
};