class Solution {
public:

    vector<int> prefix_function(string pattern){

        vector<int> prefix(pattern.size(),0) ;

        for(int i=1; i<pattern.size(); i++){
            int j=prefix[i-1];
            while(j>0 && pattern[i] != pattern[j]){
                j = prefix[j-1];
            }

            if(pattern[i] == pattern[j]){
                j++;
            }
            prefix[i] = j ;
        }
        return prefix ;
    }


    int strStr(string str, string pattern) {

        vector<int> prefix = prefix_function(pattern); 

        int i=0, j=0, index=-1;

        while(i<str.size()){

            if(str[i] == pattern[j]){
                j++;
                i++;
            }
            else{
                if(j!=0){
                    j = prefix[j-1];
                }
                else{
                    i++;
                }
            }

            if(j == pattern.size()){
                index = i - pattern.size();
                break;
            }

        }
        return index;
    }
};