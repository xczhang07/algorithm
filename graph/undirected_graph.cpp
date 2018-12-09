/*

the graph contains n nodes, which in the range [0,n-1].
following code demos the dfs, bfs traversal for undirected graph with cyclic and acyclic.
there is also a function called detectCircle for undirected graph.

*/


void DFSUtil(unordered_map<int, vector<int>>& g, int idx, vector<int>& ret, vector<bool>& visited)
{
    if(visited[idx])
        return;
    visited[idx] = true;
    ret.push_back(idx);
    for(int i = 0; i < g[idx].size(); ++i)
    {
        if(!visited[g[idx][i]])
            DFSUtil(g, g[idx][i], ret, visited);
    }
}

vector<int> DFS(vector<pair<int,int>>& edges, int n)
{
    vector<int> ret;
    if(edges.size() == 0)
        return ret;
    /* build the graph according to the input edges */
    unordered_map<int, vector<int>> g;
    vector<bool> visited(n, false);
    for(auto e : edges)
    {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }
    DFSUtil(g, 0, ret, visited);
    return ret;
}

vector<int> BFS(vector<pair<int,int>>& edges, int n)
{
    vector<int> ret;
    if(edges.size() == 0)
        return ret;
    unordered_map<int, vector<int>> g;
    vector<bool> visited(n, false);
    for(auto e : edges)
    {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; ++i)
        {
            int t = q.front();
            q.pop();
            ret.push_back(t);
            for(int j = 0; j < g[t].size(); ++j)
            {
                if(!visited[g[t][j]])
                {
                    visited[g[t][j]] = true;
                    q.push(g[t][j]);
                }
            }
        }
    }
    return ret;
}

bool isCircleUtil(unordered_map<int,vector<int>>& g, vector<bool>& visited, int idx, int parent)
{
    visited[idx] = true;
    for(int i = 0; i < g[idx].size(); ++i)
    {
        if(!visited[g[idx][i]])
        {
            if(isCircleUtil(g, visited, g[idx][i], idx))
                return true;
        }
        else if(g[idx][i] != parent)
            return true;
    }
    return false;
}

bool isCircle(vector<pair<int,int>>& edges, int n)
{
    vector<int> ret;
    if(edges.size() == 0)
        return false;
    unordered_map<int, vector<int>> g;
    vector<bool> visited(n,false);
    for(auto e : edges)
    {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }
    int parent = -1;
    return isCircleUtil(g, visited, 0, -1);
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> edges = {{0,1}, {0,2}, {0,4}, {2,3}, {2,5}};
    //vector<pair<int, int>> edges = {{0,1}, {2,0}, {1,2}};
    
     vector<int> ret = DFS(edges, 6);
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<" ";
    cout<<endl;
    
    ret = BFS(edges, 6);
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<" ";
    cout<<endl;
    
    if(isCircle(edges, 6))
        cout<<"there is a circle in graph"<<endl;
    else
        cout<<"there is not a circle in graph"<<endl;
    return 0;
}
