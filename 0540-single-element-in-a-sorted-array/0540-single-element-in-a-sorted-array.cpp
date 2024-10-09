class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
       if(n == 1) return arr[0];
       if(arr[0] != arr[1]) return arr[0];
       if(arr[n-1] != arr[n-2]) return arr[n-1];

        int l = 1, h = n-2;

        // we are in left
        while(l <= h){
            int m = (l+h)/2;

            if(arr[m] != arr[m-1] && arr[m] != arr[m+1]){ return arr[m];}

            if((m % 2 == 1 && arr[m] == arr[m-1]) || m % 2 == 0 && arr[m] == arr[m+1]){
                l = m+1;
            }
            // we are in right
            else{
                h = m - 1;
            }
        }
        return -1;
    }
};