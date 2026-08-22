class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
       vector<int>v(n);
       vector<int>v1(n);
       stack<int>s;
       stack<int>s1;
       for(int i=n-1;i>=0;i--){
        while(!s.empty()&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            v[i]=n-i;
        }
        else{
            v[i]=s.top()-i;
        }
        s.push(i);
       }
          for(int i=0;i<n;i++){
        while(!s1.empty()&&arr[s1.top()]>arr[i]){
            s1.pop();
        }
        if(s1.empty()){
            v1[i]=i+1;
        }
        else{
            v1[i]=i-s1.top();
        }
        s1.push(i);
       } 
       
    long long sum = 0;
    int mod = 1e9 + 7;

    for(int i = 0; i < n; i++){
        sum = (sum + (long long)arr[i] * v[i] * v1[i]) % mod;
    }

    return sum;

    }
};