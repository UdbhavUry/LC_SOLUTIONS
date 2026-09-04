class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>v(nums.size());
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                v[i]=maxi;
            }
            v[i]=maxi;

        }
        int result=nums.size();
        int mini=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<mini){
                mini=nums[i];
            }

            if(v[i]-mini<=k){
                result=min(result,i);
            }

        }
        if(result==nums.size()){
            return -1;
        }
        return result;
       
        
        
    }
};