class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>lse( n,0);
        vector <int>rse(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty()&& heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                lse[i]=-1;

            }
            else{
                lse[i]=s.top();
            }
            s.push(i);
        } stack<int>s2;
        for(int i=n-1;i>=0;i--){
            while(!s2.empty()&& heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(s2.empty()){
                rse[i]=n;

            }
            else{
                rse[i]=s2.top();
            }
            s2.push(i);
        } 
        int maxA=0;
        for(int i=0;i<n;i++){
            int width=rse[i]-lse[i]-1;
            int area=heights[i]*width;
            maxA=max(maxA,area);
        }
        return maxA;
        
        
    }
};