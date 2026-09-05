class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int MAX = INT_MIN;

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        for(int i =0 ; i<n ; i++){
            MAX = max(MAX , nums[i]);
            
            int IS = MAX - suffixMin[i];

            if(IS <= k){
                return i;
            }
        }

        return -1;
    }
};