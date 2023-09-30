class Solution {
public:

    /* kyunki hum last ya beginning se card utha skte h isliye hum jo nahi lenge us size ki window nikal lenge aur fir utne ka sum minus kar denge totalsum mei se taaki bache hue ka maximum store kar sake */

    int maxScore(vector<int>& cardPoints, int k) {
        
        int i=0, j=0, n=cardPoints.size(), sum=0, ans=0, leavingWindow=n-k;

        int totalSum = 0;
        for(auto it : cardPoints){
            totalSum += it ;
        }

        while(j<n){

            sum += cardPoints[j];

            if(j-i+1 < leavingWindow){
                j++;
            }
            else if(j-i+1 == leavingWindow){
                ans = max(ans, totalSum-sum);
                j++;
            }
            else if(j-i+1 > leavingWindow){
                while(j-i+1 > leavingWindow){
                    sum -= cardPoints[i] ;
                    i++;
                }
                if(j-i+1 == leavingWindow){
                    ans = max(ans, totalSum-sum);
                }
                j++;
            }
        }

        return ans ;
    }
};