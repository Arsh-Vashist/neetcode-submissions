class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recpath, vector<vector<int>>& edges){
        vis[src] = true;
        recpath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    if(isCycle(v, vis, recpath, edges)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }

    void toposort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& edges){
        vis[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    toposort(v, vis, s, edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        //if cycle exists : return empty vector
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recpath, edges)){
                    return ans;
                }
            }
        }

        //topo sorted order
        //if no cycle : means we have DAG and we can perform and we return the topo order

        stack<int> s;
        vis.assign(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                toposort(i, vis, s, edges);
            }
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};