class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s ;

        bool toBePushed = true;

        for(int i=0 ; i<n ; i++){
            
            if(s.size() == 0 || asteroids[i] > 0){
                s.push(asteroids[i]);
            }
            else if(asteroids[i] < 0){
                while(!s.empty() && s.top() > 0){
                    int prevAsteroid = s.top();
                    if(prevAsteroid > abs(asteroids[i])){
                        toBePushed = false;
                        break;
                    }
                    else if(prevAsteroid < abs(asteroids[i])){
                        s.pop();
                    }
                    else{
                        s.pop();
                        toBePushed = false;
                        break;
                    }
                }
                if(toBePushed){
                    s.push(asteroids[i]);
                }
                else{
                    toBePushed = true;
                }
            }
        }

        vector<int> ans;
        while(s.size() != 0){
            ans.push_back(s.top());
            s.pop() ;
        }

        reverse(ans.begin() , ans.end());
        return ans ;
    }
};