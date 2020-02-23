class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxElem = nums[0];
        for (int i = 1 ; i < nums.size() ; i ++) {
            maxElem = max(maxElem, nums[i]);
        }
        
        int lo = 0, hi = maxElem, mid;
        
        while (lo < hi) {
            mid = (lo + hi) / 2;
            
            int count = 0;
            // find the count of all pairs whose distance is less than or equal to mid
            int lef = 0;
            int rig = 0;
            while (rig < nums.size()) {
                while (nums[rig] - nums[lef] > mid) {
                    lef ++;
                }
                // nums[rig] - nums[lef] <= mid
                count += rig - lef;
                rig ++;
            }
            //
            
            if (count >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};
