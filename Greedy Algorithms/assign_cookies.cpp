class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int greedFactorIndex=0 ; int cookieSize=0 ;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int count=0 ;
        while(greedFactorIndex<g.size() && cookieSize<s.size()){
            if( g[greedFactorIndex] <= s[cookieSize] ){
                count++ ;
                greedFactorIndex++;
                cookieSize++;
            }
            else if( g[greedFactorIndex] < s[cookieSize] ){
                greedFactorIndex++ ;
            }
            else{
                cookieSize++;
            }
        }

        return count ;
    }
};