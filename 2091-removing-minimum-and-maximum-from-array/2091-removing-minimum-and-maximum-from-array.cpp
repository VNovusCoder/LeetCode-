class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minidx = -1;
        int maxidx = -1;
        int n = nums.size();

        int Max = INT_MIN;
        int Min = INT_MAX;

        for(int i =0 ;i<n ; i++){
            if(nums[i] > Max){
                Max = nums[i];
                maxidx = i;
            }
            if(nums[i] < Min){
                Min = nums[i];
                minidx = i;
            }
        }   

        int awayidx = -1;
        int closeidx = -1;

        if(minidx  > maxidx){
            awayidx = minidx;
            closeidx = maxidx;
        }
        else{
            awayidx = maxidx;
            closeidx = minidx;
        }

        int both = (closeidx + 1)+ (n - awayidx);
        int left = awayidx + 1;
        int right = (n - closeidx);

        cout<<both<<" "<<left<<" "<<right;
        return min(both, min(left,right));


    }
};