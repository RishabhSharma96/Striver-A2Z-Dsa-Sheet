class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        for(int i=0 ; i<n ; i++){
            int leftNeighbour = 2*i + 1;
            int RightNeighbour = 2*i + 2;
            if(leftNeighbour<n && a[i] < a[leftNeighbour]){
                return false;
            }
            else if(RightNeighbour<n && a[i] < a[RightNeighbour]){
                return false;
            }
        }
        
        return true ;
    }
};