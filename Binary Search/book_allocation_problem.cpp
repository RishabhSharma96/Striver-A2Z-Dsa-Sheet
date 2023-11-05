//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int countStudents(int arr[], int n, int pages) {
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            }
            else {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    
    int findPages(int arr[], int n, int m) {

        if (m > n) return -1;
        
        int sum = 0, maxi=INT_MIN ;
        
        for(int i=0 ; i<n ;i++){
            sum += arr[i] ;
            maxi = max(maxi,arr[i]);
        }
    
        int low = maxi;
        int high = sum;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(arr,n, mid);
            if (students > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};