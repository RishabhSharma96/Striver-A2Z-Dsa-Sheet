class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {

        int xorr = 0;
    
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ a[i];
            xorr = xorr ^ (i + 1);
        }
    
        int number = (xorr & ~(xorr - 1));
    
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] & number) != 0) {
                one = one ^ a[i];
            }
            else {
                zero = zero ^ a[i];
            }
        }
    
        for (int i = 1; i <= n; i++) {
            if ((i & number) != 0) {
                one = one ^ i;
            }
            else {
                zero = zero ^ i;
            }
        }
    
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == zero) cnt++;
        }
    
        if (cnt == 2) return {zero, one};
        return {one, zero};
    }
};