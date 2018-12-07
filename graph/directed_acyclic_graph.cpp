/* dfs travel for directed acyclic graph */

void DFSUtil(vector<int>& ret, unordered_map<int, vector<int>>& graph, vector<bool>& visited, int idx)
{
    ret.push_back(idx);
    visited[idx] = true;
    for(int i = 0; i < graph[idx].size(); ++i)
    {
        if(!visited[graph[idx][i]])
            DFSUtil(ret, graph, visited, graph[idx][i]);
    }
    return;
}

/* dfs travel for directed acyclic graph */
vector<int> DFS(vector<pair<int, int>>& edges, int n)
{
    vector<int> ret;
    if(edges.size() == 0)
        return ret;
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n,false);
    /* building graph */
    for(auto e: edges)
        graph[e.first].push_back(e.second);
    DFSUtil(ret, graph, visited, 0);
    return ret;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> edges = {{0,1}, {0,2}, {1,2}, {1,4}, {2,3}, {3,5}, {3,6}, {4,5}, {5,6}};
    vector<int> ret = DFS(edges, 7);
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<" ";
    cout<<endl;
    return 0;
}

/*
Output as following:
0 1 2 3 5 6 4
*/

vector<int> BFS(vector<pair<int,int>>& edges, int n)
{
    vector<int> ret;
    if(edges.size() == 0)
        return ret;
    /* building the graph */
    vector<bool> visited(n,false);
    unordered_map<int, vector<int>> graph;
    for(auto e: edges)
        graph[e.first].push_back(e.second);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; ++i)
        {
            int t = q.front();
            ret.push_back(t);
            q.pop();
            for(auto e: graph[t])
            {
                if(!visited[e])
                {
                    visited[e] = true;
                    q.push(e);
                }
            }
        }
    }
    return ret;
}
