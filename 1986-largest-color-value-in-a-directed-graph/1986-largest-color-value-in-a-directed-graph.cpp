class Solution {

private:
    vector<int>to;
    vector<int>disc;
    vector<int>low;
    stack<int>st;

    vector<int>ziphash;

    vector<vector<int>>gr;
    vector<vector<long long>>dp;

    int n;
    int comp=1;
    int zipcomp=0;

    long long ans=1;
    vector<int>color;

    void tarjan(int u){

        disc[u]=low[u]=comp;
        st.push(u);
        comp++;

        for(auto&v:gr[u]){
            if(!ziphash[v]){
                if(disc[v]){
                    low[u]=min(low[u],disc[v]);
                }
                else{
                    tarjan(v);
                    low[u]=min(low[u],low[v]);
                }
            }
        }

        if(low[u]==disc[u]){
            int v;
            zipcomp++;
            do{
                v=st.top();
                st.pop();
                ziphash[v]=zipcomp;
            }while(v!=u);
        }
    }

    void bfs(string&colors){

        queue<int>q;

        for(int i=0;i<n;i++){
            if(!to[i]){
                q.push(i);
                dp[i][colors[i]-'a']=(long long)1;
            }
        }

        while(!q.empty()){

            int u=q.front();
            q.pop();

            for(auto&v:gr[u]){
                
                for(int i=0;i<26;i++){
                    if(i==colors[v]-'a'){
                        dp[v][i]=max((long long)dp[v][i],(long long)dp[u][i]+(long long)1);
                        ans=max(ans,(long long)dp[v][i]);
                    }
                    else{
                        dp[v][i]=max((long long)dp[v][i],(long long)dp[u][i]);
                    }
                }

                to[v]--;

                if(!to[v]){
                    q.push(v);
                }        
            }

        }

    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        n=colors.size();
        int m = edges.size();

        if((long long)m>(long long)n*((long long)n-1)/2){
            return -1;
        }

        to.resize(n,0);
        disc.resize(n,0);
        low.resize(n,0);
        gr.resize(n);
        ziphash.resize(n,0);
        color.resize(26,0);
        dp.resize(n,vector<long long>(26,0));

        for(auto&ed:edges){
            if(ed[0]==ed[1]){
                return -1;
            }
            gr[ed[0]].push_back(ed[1]);
            to[ed[1]]++;
        }

        for(int i=0;i<n;i++){
            if(!disc[i]){
                tarjan(i);
            }
        }


        if(zipcomp<n){
            return -1;
        }

        bfs(colors);

        return ans;

    }
};