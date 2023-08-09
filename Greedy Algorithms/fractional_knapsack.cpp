    //class implemented
    /*
    struct Item{
    int value;
    int weight;
    };
    */


    class Solution
    {
    public:
    //Function to get the maximum total value in the knapsack.

    bool static comparator(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
        }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort (arr, arr+n , comparator);
        
        int i=0; double collectedValue = 0 ; 
        
        while(i<n){
            if(arr[i].weight <= W){
                collectedValue += arr[i].value ;
                W = W-arr[i].weight;
            }
            else{
                collectedValue += (arr[i].value/(double)arr[i].weight)*(double)W ;
                W=0;
            }
            i++;
        }
        
        return collectedValue;
    }
        
    };