class Solution {
public:
    long long countCommas(long long n) {
        long long t=999;
        long long count=0;
        while(n-t>0){
            count+=n-t;
            t=t*1000+999;
        }
        return count;
    
       
        
    }
};