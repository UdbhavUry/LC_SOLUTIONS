class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        } int maxi=0;
        int count=0;
        int prev=0;
        for(auto it:mpp){
          int  curr=it.first;
            if(curr-1==prev){
                count++;
                prev=curr;
            }
            else{
                maxi=max(count,maxi);
                count=1;
                prev=curr;
            }
        }
        maxi=max(count,maxi);
        return maxi;
        
    }
};