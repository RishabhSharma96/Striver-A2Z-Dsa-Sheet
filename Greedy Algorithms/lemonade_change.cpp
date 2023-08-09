class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size() ;
        int fiveBill=0 , tenBill=0 ;

        for(auto bill : bills){
            if(bill == 5){
                fiveBill++ ;
            }
            else if(bill == 10){
                if(fiveBill > 0){
                    fiveBill--;
                    tenBill++;
                }
                else{
                    return false;
                }
            }
            else{
                if(tenBill > 0 && fiveBill > 0){
                    tenBill--;
                    fiveBill--;
                }
                else if(fiveBill >= 3){
                    fiveBill -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
        
    }
};