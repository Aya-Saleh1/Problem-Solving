// Bridge is edge when we remove it, the graph becomes disconnected
// Implemented using DFS tree, and Targin Algo 

void IS_BRIDGE(int v,int to); // some function to process the found bridge
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

    // Using tin and low
    // tin[u] the first time the dfs enters u
    // low[v] earliest node up we can reach it (using back edge)
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
          // back edge 
            low[v] = min(low[v], tin[to]); 
        } else {
          // Tree edge 
            dfs(to, v);
            low[v] = min(low[v], low[to]); // if i can escape then my child can
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
