#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    int vert;
    vector<vector<int>> adlis;
public:
    graph(int n)
    {
        vert = n;
        adlis.resize(n);
    }
    void add_edge(int u, int v)
    {
        adlis[u].push_back(v);
        adlis[v].push_back(u);
    }
    void print_graph()
    {
        for (int i = 0; i < vert; i++)
        {
            cout << i << " -> ";
            for(int no : adlis[i])
            {
                cout << no << " ";
            }
            cout << endl;
        }
    }

    void bfs(vector<bool>& vis, queue<int> q)
    {
        if(q.empty())
            return;

        int node = q.front();
        q.pop();
        cout<< node << " - ";
        for(int i : adlis[node])
        {
            if(!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
        bfs(vis, q);
    }
    void dfs(vector<bool>& vis, int o)
    {
        vis[o] = true;
        cout << o << " - ";
        for(auto v:adlis[o])
        {
            if(!vis[v])
                dfs(vis,v);
        }
        return;
    }
};

int main()
{
    cout << "Input no of vertices: ";
    int n;
    cin >> n;
    graph g(n);
    cout << "Input no of edges: ";
    int e;
    cin >> e;
    for(int i=0; i<e; i++)
    {
        cout << "from: ";
        int f;
        cin >> f;
        cout << "to: ";
        int t;
        cin >> t;
        g.add_edge(f, t);
    }

    g.print_graph();

    vector<bool> vis1(n, false);
    queue<int> q;
    // BFS traversal from vertex 0
    cout << "BFS: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            vis1[i] = true;
            q.push(i);
            g.bfs(vis1, q);
        }
    }
    cout << endl;
    cout << "DFS: " << endl;
    vector<bool> visited2(15, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(visited2, i);
        }
    }
    cout << endl;
}