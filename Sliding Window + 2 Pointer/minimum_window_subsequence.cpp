// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        
        int n=str1.size(), m=str2.size();
        int i=0, j=0, mini=1e9, start=-1, k=0;
        
        while(j<n){
            if(str1[j]==str2[k]){
                k++;
            }
            if(k==m){
                i=j;
                k=m-1;
                while(i>=0 && k>=0){
                    if(str1[i]==str2[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                if(j-i+1<mini){
                    mini=j-i+1;
                    start=i;
                }
                k=0;
                j=i+1;
            }
            j++;
        }
        return mini == 1e9 ? "" : str1.substr(i, mini);
    }

};