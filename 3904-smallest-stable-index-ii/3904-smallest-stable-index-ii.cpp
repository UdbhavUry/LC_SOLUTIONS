class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();int mini=INT_MAX;
         vector <int>minimum(n);
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mini){
                mini=nums[i];
                minimum[i]=mini;
            }
            minimum[i]=mini;
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-minimum[i]<=k){
                return i;
            }
            
        }
        return -1;


        
    }
};