class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // unordered_set<int>s(nums.begin(),nums.end());
        // for(int i=1;i<=100;i++){
        //     if(!s.count(k*i)){
        //         return k*i;
        //     }
        // }
        // return k* 101;;
       vector<bool> freq(101,0);

        for(int i=0;i<nums.size();i++)
        freq[nums[i]] = 1;

        int i = k;
        while(i <= 100) {
            if(!freq[i])
            return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
        
    }
};