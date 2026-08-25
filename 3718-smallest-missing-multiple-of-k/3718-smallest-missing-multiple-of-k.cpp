class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int ans = 0;
        int max_val = 0;
        unordered_set<int> s;

        for(int val : nums){
            s.insert(val);
        }


        for(int i =k ; i<=100 ; i = i + k){
            if(s.find(i) == s.end()){
                ans = i;
                break;
            }
            max_val = max(max_val , i);
        }

        if(ans == 0){
            ans = max_val + k;
        }
    
        return ans ;
    }
};