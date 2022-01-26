class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
        int mult=1;
        int right[nums.size()];
        //1. right product array
        for(int i=nums.size()-1; i>=0; i--)
        {
            mult*=nums[i];
            right[i]=mult;
        }
        
        //2.Make result with maintaining of left product
        mult=1;
        vector<int> res(nums.size());
        for(int i=0; i<res.size()-1; i++)
        {
            res[i]=mult*right[i+1];
            mult*=nums[i];
        }
        res[nums.size()-1]=mult;
        return res;
    }
};