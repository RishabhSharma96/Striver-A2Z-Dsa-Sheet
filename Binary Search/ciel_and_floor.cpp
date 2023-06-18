int floor(int nums[], int n, int target){

        long long i = 0, j = n-1;

        long long mid = i + (j - i) / 2;
        int ans = -1;
        
        while (i <= j){
            
            mid = i + (j - i) / 2;
            if (nums[mid] <= target)
            {
                ans = nums[mid];
            }

            if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return ans;
    }
    
    int ciel(int nums[], int n, int target){

        long long i = 0, j = n-1;

        long long mid = i + (j - i) / 2;
        int ans = -1;
        
        while (i <= j){
            
            mid = i + (j - i) / 2;
            if (nums[mid] >= target)
            {
                ans = nums[mid];
            }

            if (nums[mid] >= target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
            
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(int nums[], int n, int target) {
        sort(nums,nums+n);
        pair<int,int> cf;
        cf.first = floor(nums,n,target);
        cf.second = ciel(nums,n,target);
        return cf;
    }