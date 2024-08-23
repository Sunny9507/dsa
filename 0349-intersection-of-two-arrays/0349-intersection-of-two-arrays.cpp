class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int>st1, st2;
        for(int v:nums1) st1.insert(v);
        for(int v:nums2) st2.insert(v);

        set<int>st;
        for(int v:st1)
        {
            if(st2.find(v) != st2.end()) 
                st.insert(v);
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};