class Solution {
public:
    void rec(int prev,int& m,string&temp,vector<string>&cols){
        if(temp.size()==m){
            cols.push_back(temp);
            return;
        }

        for(int i=1;i<=3;i++){
            if(i!=prev){
                temp.push_back('0'+i);
                rec(i,m,temp,cols);
                temp.pop_back();
            }
        }
    }
    int colorTheGrid(int m, int n) {
        //0,1,2,3
        //unclored,red,green,blue
        vector<vector<int>>grid(m,vector<int>(n));
        // how may different colm are possible?
        // only 3*2^(m-1) possibilites,
        // what we can do is just consider each posibiltie for a column
        // and then see for next column if its feasible to place any other col
        // psoibilties

        // use recursion to make a string for all possibilities
        vector<string>cols;
        string temp="";
        rec(0,m,temp,cols);
        int mod=1e9+7;
        // now create a adjancy list from those cols possibilty where there can be edge
        // means they can be adjacent
        // O(9*2^m)
        unordered_map<string,vector<string>>adj;
        for(auto it:cols){
            for(auto it2:cols){
                string x=it;
                string y=it2;
                bool f=true;
                for(int i=0;i<m;i++){
                    if(x[i]==y[i]){
                        f=false;
                        break;
                    }
                }
                if(f){
                    adj[x].push_back(y);
                    //adj[y].push_back(x); //maybe this was double counting
                }
                
            }
        }

        // dp[s] representing if we end on s how many paths we could have covered in graph
        unordered_map<string,int>prev;
        // i call this rolling dp
        // we can always plaace every string as first col
        for(auto it:adj){
            prev[it.first]=1;
        }

        for(int col=1;col<n;col++){
            // now we will explore neighbourse of previous cols in graph
            unordered_map<string,int>next;
            for(auto it:prev){
                string x=it.first;
                int cnt=it.second;
                for(auto it2:adj[x]){
                    next[it2]=(next[it2]+cnt)%mod;;
                }
            }
            prev=next;
        }

        int ans=0;
        for(auto it:prev){
            ans=(ans+it.second)%mod;
        }
        return ans;
    }
};