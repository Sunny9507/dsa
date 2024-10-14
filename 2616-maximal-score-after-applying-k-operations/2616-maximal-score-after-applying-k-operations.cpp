#include <vector>
#include <cmath> // For ceil function
#include <limits.h> // For INT_MIN

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long sum = 0; 

        priority_queue<int>pq(begin(nums), end(nums)); //Heapify o (n)
        while(k--){
            int maxiEl = pq.top();
            pq.pop();

            sum += maxiEl;
            maxiEl = ceil(maxiEl/3.0);
            pq.push(maxiEl);

        }
     
        return sum; 
    }
};
