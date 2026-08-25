class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            long long hours=0;
            for(int i:piles){
                hours+=(i+mid-1)/mid;
            }
           
            
             if(hours<=h){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};