class Solution {
public:
    int minOperations(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                if(i + 2 >= n) {return -1;}
                arr[i] = 1;
                arr[i+1] = arr[i+1] ^ 1;
                arr[i+2] = arr[i+2] ^ 1;
                ans++;
            }
        }
        return ans;
    }
};