class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;

        map<int,int>m;
        for(auto x: arr1)
            m[x]++;

        for(auto temp : arr2){
            if(m.find(temp) != m.end()){
                auto x = m.find(temp);
                int cnt = x->second;  // s-> 2
                vector<int>v(cnt, temp); // v = 5 5
                ans.insert(ans.end(), v.begin(), v.end());
                m.erase(temp);
            }
        }
        for(auto x : m){
            int ele = x.first;
            int cnt = x.second;
            vector<int>v(cnt, ele);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};