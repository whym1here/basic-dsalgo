#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Edge {
public:
    int from, to;
    T cap, used;
 
    Edge() : from(-1), to(-1), cap(0), used(0) {}
 
    Edge(int _from, int _to, T _cap, T _used = 0) : from(_from), to(_to), cap(_cap), used(_used) {}  
 
    T remain() {
        return cap - used;
    }
};

// Find Max Flow in O(V ^ 2 * E)
template<typename T>
class Flow { // Dinic'a Algorithm
public:
    vector<Edge<T>> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t; // source = s and sink = t
    const T INF = numeric_limits<T>::max();
    vector<int> ptr, lvl;
    queue<int> q;
    
    Flow() : n(0), m(0), s(-1), t(-1) {}
    
    // _s = source, and _t = sink
    Flow(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }
 
    void add_edge(int u, int v, T cap) {
        adj[u].push_back(m++);
        edges.emplace_back(u, v, cap);
        adj[v].push_back(m++);
        edges.emplace_back(v, u, 0);
    }
 
    bool bfs() {
        fill(lvl.begin(), lvl.end(), -1);
        lvl[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& id: adj[u]) {
                int v = edges[id].to;
                if (lvl[v] == -1 and edges[id].remain() > 0) {
                    lvl[v] = lvl[u] + 1;
                    q.push(v);
                }
            }
        }
        return lvl[t] != -1;
    }
 
    T dfs(int u, T min_cap) {
        if (min_cap == 0) return 0;
        if (u == t) return min_cap;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].to;
            T node_rem = edges[id].remain();
            if (lvl[v] != lvl[u] + 1) continue;
            if (node_rem <= 0) continue;
            int path_cap = dfs(v, min(node_rem, min_cap));
            if (path_cap == 0) continue;
            edges[id].used += path_cap;
            edges[id ^ 1].used -= path_cap;
            return path_cap;
        }
        return 0;
    }
 
    T flow() {
        T res = T(0);
        while (true) {
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (T pushed = dfs(s, INF)) {
                res += pushed;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}