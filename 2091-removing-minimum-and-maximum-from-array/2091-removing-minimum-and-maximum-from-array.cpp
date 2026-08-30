class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;}
        
        int mini =INT_MAX;
        int maxi
        =INT_MIN;
        int mi=0,ma=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ma=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                mi=i;
            }
        }
        int right=max(ma,mi);
        int left=min(ma,mi);
         int option1 = right + 1;                
        int option2 = n - left;                  
         int option3 = (left + 1) + (n - right); 

    return min({option1, option2, option3});
       

        
    }
};