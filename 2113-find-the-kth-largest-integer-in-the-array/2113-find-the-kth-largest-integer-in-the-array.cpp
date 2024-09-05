class Solution {
public:
    
    static bool compare(string& a, string& b)
    {
        if(a.size() == b.size())
            return a > b;
        
        // if size is different then sort on the basis of no. of digits
        
        else
        {
            return a.size() > b.size();
        }
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(), nums.end(), compare);
        
        return nums[k - 1];
    }
};