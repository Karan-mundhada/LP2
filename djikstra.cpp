#include<iostream>
using namespace std;
#include<vector>
#include<climits>

class Graph
{
    public:
    vector<vector<int>> graph;
    Graph(int n)
    {
        graph.resize(n, vector<int>(n, 0));
    }
    void create(int s, int d, int w)
    {
        graph[s][d] = w;
        graph[d][s] = w;
    }

    int minvertex(vector<int> distance,vector<int> djik)
    {
        int minn=INT_MAX;
        int minindex=-1;
        for(int i=0;i<distance.size();i++)
        {
            if(!djik[i] && distance[i]<=minn)
            {
                minn=distance[i];
                minindex=i;
            }
        }
        return minindex;
    }

    void djikstra(int start)
    {
        int n=graph.size();
        vector<int> dist(n,INT_MAX);
        vector<int> vis(n,false);
        dist[start]=0;

        for(int u=0;u<n-1;u++)
        {
            int index=minvertex(dist,vis);
            vis[index]=true;
            for(int v=0;v<n;v++)
            {
                if(!vis[v] && graph[index][v]!=0 && dist[index]+graph[index][v]<dist[v])
                {
                    dist[v]=dist[index]+graph[index][v];
                }
            }

        }
        cout<<"Distance of each vertex from source "<<endl;
        cout<<"Vertex\t\t\t"<<"Distance"<<endl;
        for(int i=0;i<dist.size();i++)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
};

int main(){
    cout<<"enter vertices and  edges"<<endl;
    int v,e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++)
    {
        cout<<"ENter s,d,w"<<endl;
        int s,d,w;
        cin>>s>>d>>w;
        g.create(s,d,w);
            }
    g.djikstra(0);
    return 0;
}


// 0
// 1
// 2
// ENter s,d,w
// 0
// 2
// 4
// ENter s,d,w
// 1
// 3
// 7
// ENter s,d,w
// 3
// 4
// 2
// ENter s,d,w
// 2
// 4
// 3
// ENter s,d,w
// 3
// 5
// 1
// ENter s,d,w
// 4
// 5
// 5
// ENter s,d,w
// 1
// 2
// 1
// Distan