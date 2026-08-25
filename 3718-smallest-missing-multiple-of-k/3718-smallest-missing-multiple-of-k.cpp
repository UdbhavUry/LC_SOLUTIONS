class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=1;i<=100;i++){
            if(!s.count(k*i)){
                return k*i;
            }
        }
        return k* 101;;

        
    }
};