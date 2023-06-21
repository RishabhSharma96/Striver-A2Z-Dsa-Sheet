class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ; // {element,index};
        for(int i=0 ; i<N ; i++){
            pq.push({arr[i],i}) ;
        }
        
        int num=0;
        int it=0 ;
        while(!pq.empty()){
            auto node = pq.top() ;
            pq.pop() ;
            int value = node.first;
            int index = node.second;
            
            
            if(value == num){
                arr[index] = it ;
            }
            else{
                arr[index] = it+1;
                it++ ;
            }
            
            num = value ;
            
        }
        
        return arr ;
    }

};