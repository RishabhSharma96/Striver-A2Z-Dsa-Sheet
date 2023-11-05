class Solution {

public:

    static bool comparator(vector<int> a , vector<int>b){
        return a[1] < b[1] ;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);

        pair<int,int> p;
        p.first = intervals[0][0];
        p.second = intervals[0][1];

        int count=0 ;
        for(int i=1 ; i<n ; i++){
            if(intervals[i][0] < p.second){
                count++;
            }
            else{
                p.first = intervals[i][0];
                p.second = intervals[i][1];
            }
        }
        return count;
    }
};